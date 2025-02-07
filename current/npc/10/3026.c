
// 自动生成：/make/npc/make-collect

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <music.h>
#include <equip.h>

inherit OFFICER;

void do_task();

// 函数：获取人物造型
int get_char_picid() { return 5505; }
void do_welcome(string arg);

// 函数：构造处理
void create()
{
        set_name("程强");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      
//        set("level",41);
//        set("legend",({32*11+1}));    
	set("mpLegend",([40:({32*11+1})]));
	set("mpLegend2",([0:({32*46+20,32*46+23,}),40:({32*11+3,32*11+10}),]));
        setup();
}

// 函数：对话处理
void do_look( object who )
{
	string tmp="";
        tmp += CHAIN_D->get_chain_menu(who,this_object());
        if ( (who->get_level() >= 40 && !who->get_legend(TASK_11,1)) || (who->get_legend(TASK_11,1)&&!who->get_legend(TASK_11,3)) ) 
		tmp += sprintf(ESC HIY "寻找信物\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( (who->get_legend(TASK_11,3) && !who->get_legend(TASK_11,4)) || (who->get_legend(TASK_11,4)&&!who->get_legend(TASK_11,5)) ) 
		tmp += sprintf(ESC HIY "送去信物\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( who->get_legend(TASK_11,9)&&!who->get_legend(TASK_11,10) ) 
		tmp += sprintf(ESC HIY "送去信物\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( who->get_legend(TASK_46,19)&&!who->get_legend(TASK_46,20) ) 
		tmp += sprintf(ESC HIY "除掉恶匪\ntalk %x# welcome.6\n",getoid(this_object())); 
         if ( who->get_legend(TASK_46,20)&&!who->get_legend(TASK_46,23) ) 
		tmp += sprintf(ESC HIY "寻回赃物\ntalk %x# welcome.6\n",getoid(this_object())); 
         if ( who->get_legend(TASK_46,23)&&!who->get_legend(TASK_46,24) ) 
		tmp += sprintf(ESC HIY "转交信函\ntalk %x# welcome.6\n",getoid(this_object())); 
 
        send_user( who, "%c%s", ':', sprintf( "%s：\n    我只是一介穷苦书生，家境贫寒，一次偶然看见了秦宫的贝贝小姐，对她产生了一种前所未有的怜爱与爱怜。\n", get_name())
        + tmp +
        ESC"离开"
         );
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,p;
        object who,item,obj;  
        string cmd1;
       	string *nTmp,tmp;     
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if (who->get_level() >= 40 && !who->get_legend(TASK_11,1))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    自从我见过贝贝小姐后，就一直朝思暮想，无奈家境贫寒，想送点东西给贝贝小姐表达我的心意，可是实在没有什么能拿得出手的。\n    我一直就想送她一条珍珠项链，可你看我这样子，就知道买不起，不过我听说东海渔村的虾兵蟹将会有，你能去给我找一串来吗？\n"ESC"接受任务\ntalk %x# welcome.2\n"ESC"离开", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_11,1) && !who->get_legend(TASK_11,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    如果没有信物，那贝贝小姐又怎能与我相识呢？\n"ESC"离开", me->get_name()));
        	else if ( who->get_legend(TASK_11,2) && !who->get_legend(TASK_11,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    感谢你替我找到了合适的信物，可我一介书生怎能进入这吕府呢？\n"ESC"完成任务\ntalk %x# welcome.3\n"ESC"离开", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_11,3) && !who->get_legend(TASK_11,4) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    唉，我连套象样的出门衣服都没有，寒酸啊～～还是你给我送去这信物好吗？\n"ESC"接受任务\ntalk %x# welcome.4\n"ESC"离开", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_11,4) && !who->get_legend(TASK_11,5) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    贝贝小姐怎么回答我的？你送去项链了吗？\n"ESC"离开", me->get_name()));
        	else if ( who->get_legend(TASK_11,9) && !who->get_legend(TASK_11,10) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    哈哈哈哈哈哈！我太高兴了，贝贝小姐居然会给我送来她亲手制作的糕点！\n"ESC"完成任务\ntalk %x# welcome.5\n"ESC"离开", me->get_name(),getoid(me)));

        	break;
        case 2:
        	if(who->get_level() >= 40 && !who->get_legend(TASK_11,1))
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_11,1);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"秦国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,3,"情锁秦宫（1）" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"情锁秦宫（1）");
        	}
        	break;
       case 3:
        	if ( who->get_legend(TASK_11,2) && !who->get_legend(TASK_11,3) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"珍珠项链",1) != 1 )
        			return;
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_11,3);
			who->add_exp(4500);
			who->add_potential(140);
			who->add_cash(3500);
			send_user(who,"%c%s",';',"情锁秦宫（1） 经验 4500 潜能 140 金钱 3500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,3,"" );
			me->do_welcome(1);
        	}
        	break;        
        case 4:
        	if( who->get_legend(TASK_11,3) && !who->get_legend(TASK_11,4) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;        		
			TASK_LEGEND_D->give_item(who,"item/98/0002",1);
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_11,4);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"秦国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,4,"情锁秦宫（2）" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"情锁秦宫（2）");
        	}
        	break;
       case 5:
        	if ( who->get_legend(TASK_11,9) && !who->get_legend(TASK_11,10) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"糕点",1) != 1 )
        			return;
        		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),40,HEAD_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			TASK_LEGEND_D->give_item(who,tmp,1);
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_11,10);
			who->add_exp(4300);
			who->add_potential(138);
			who->add_cash(3800);
			send_user(who,"%c%s",';',sprintf("情锁秦宫（4） 经验 4300 潜能 138 金钱 3800 %s 1",tmp->get_name()));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,6,"" );
        	}
        	break;    
        case 6:
        	if ( who->get_legend(TASK_46,19)&&!who->get_legend(TASK_46,20) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    啊！壮士可是说那恶匪展五终于竟然是死了！真是天理昭昭，恶有恶报，多谢壮士为我报此深仇！呜呜呜……可惜我的弟弟再也回不来了，我要用这个恶贼的人头祭奠我亡弟的冤魂！\n"ESC"完成任务\ntalk %x# welcome.7\n"ESC"离开", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_46,20)&&!who->get_legend(TASK_46,21) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    唉，至于那恶匪的来历我倒也略知一二，因为当年家父曾与他同一战壕作战，虽然他从不透露自己出身，但他作战勇猛，却屡屡不服上级指令，最终杀掉了副将逃回山中，家父曾经收留过他，却不小心让他知道了家传的金龙珠，虽然从来不知道有何大用，但是却也小心收藏，那恶匪听到金龙珠几字眼睛放光，后来我的父亲死于战火，我们兄弟也流落到此，不知道他如何找到我们，最终抢走了金龙珠，我弟弟不服想上告被他残忍杀害，他还就此威逼我交出什么卷，但是 我等从来没有见过又如何得知，展五就此盘踞在平阳附近屡屡骚扰居民，而我心中真的苦不堪言。如今恶匪终于死去，我的家传至宝金龙珠也自此失去踪影，我真是对祖宗有愧，前日听一个逃出来的小喽啰说恶匪常常在诛仙阵二层南部神秘兮兮的徘徊，估计那金龙珠就藏在某个箱子里，恳求壮士再跑一趟，帮我寻回传家至宝。\n"ESC"接受任务\ntalk %x# welcome.8\n"ESC"离开", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_46,21)&&!who->get_legend(TASK_46,22) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    莫非金龙珠竟然真的就此遗失了么，我程强真的对不起程家的先祖啊。\n"ESC"离开", me->get_name(),));
		else if ( who->get_legend(TASK_46,22)&&!who->get_legend(TASK_46,23) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    大侠你就是我们程家的大恩人哪，今后有何事但凭吩咐，哪怕上刀山下火海也决不皱眉。\n"ESC"完成任务\ntalk %x# welcome.9\n"ESC"离开", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_46,23)&&!who->get_legend(TASK_46,24) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    平阳镇如今祸害已除，大家又可以安居乐业了，我将最近发生的事情写了条陈，劳烦壮士送给本国御史大人，让他宽心吧。\n"ESC"接受任务\ntalk %x# welcome.10\n"ESC"离开", me->get_name(),getoid(me)));
			
        	break;
        case 7:
        	if( who->get_legend(TASK_46,19)&&!who->get_legend(TASK_46,20) )
        	{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_46,20);
			who->add_exp(92000);
			who->add_potential(980);
			who->add_cash(93000);
			send_user(who,"%c%s",';',"平阳之乱3 经验 92000 潜能 980 金钱 93000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,71,"" );
			me->do_welcome(6);
        	}
        	break;
        case 8:
        	if ( who->get_legend(TASK_46,20)&&!who->get_legend(TASK_46,21) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_46,21);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"秦国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,72,"平阳之乱4" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"平阳之乱4");
       		}
        	break;
        case 9:
        	if( who->get_legend(TASK_46,22)&&!who->get_legend(TASK_46,23) )
        	{
			if (TASK_LEGEND_D->check_task_item(who,"金龙珠",1) != 1 )
        			return;
        		TASK_LEGEND_D->give_item(who,"item/product/64187",1);
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_46,23);
			who->add_exp(92000);
			who->add_potential(980);
			who->add_cash(93000);
			send_user(who,"%c%s",';',"平阳之乱4 经验 92000 潜能 980 金钱 93000 龙鳞战甲图纸 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,72,"" );
			me->do_welcome(6);
        	}
        	break;
        case 10:
        	if ( who->get_legend(TASK_46,23)&&!who->get_legend(TASK_46,24) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;
        		TASK_LEGEND_D->give_item(who,"item/98/0230",1); 
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_46,24);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"秦国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,73,"平阳之乱5" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"平阳之乱5");
       		}
        	break;
        }
}