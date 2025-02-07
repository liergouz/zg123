
// 自动生成：/make/npc/make8084

#include <npc.h>
#include <task.h>
#include <ansi.h>
#include <equip.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 7309; }
void do_welcome(string arg);

// 函数：构造处理
void create()
{
        set_name("燕国百姓");
	set_real_name("燕姜");
        set_city_name("燕国");
        set_2( "talk", ([
                "welcome"	: (: do_welcome :),
        ]) );
//        set("level",46);
//        set("legend",({32*12+1}));
	set("mpLegend",([45:({32*12+1,32*12+25}),50:({32*15+7})]));
	set("mpLegend2",([45:({32*12+3,32*12+27}),50:({32*15+11,32*15+14,})]));
        setup();
}

// 函数：对话处理
void do_look( object who )
{ 
	string tmp="";
	object me = this_object();
	if ( ( who->get_level() >= 45 && !who->get_legend(TASK_12,1) ) || ( who->get_legend(TASK_12,2) && !who->get_legend(TASK_12,3) ) )
	{
		tmp = sprintf(ESC HIY "郑国渠的阴风\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( ( who->get_level() >= 45 && !who->get_legend(TASK_12,25) ) || ( who->get_legend(TASK_12,25) && !who->get_legend(TASK_12,27) ) )
	{
		tmp += sprintf(ESC HIY "河道冤魂\ntalk %x# welcome.6\n",getoid(me));
	}
	if ( ( who->get_level() >= 50 && !who->get_legend(TASK_15,7) ) || ( who->get_legend(TASK_15,7) && !who->get_legend(TASK_15,8) ) )
	{
		tmp += sprintf(ESC HIY "夫人的怪病\ntalk %x# welcome.7\n",getoid(me));
	}
	if ( who->get_legend(TASK_15, 9) && !who->get_legend(TASK_15, 11) )
	{
		tmp += sprintf( ESC HIY "夫人的怪病\ntalk %x# welcome.7\n", getoid(me) );
	}
	if ( (who->get_legend(TASK_15, 11) && !who->get_legend(TASK_15, 12)) || (who->get_legend(TASK_15, 12) && !who->get_legend(TASK_15, 14)))
	{
		tmp += sprintf( ESC HIY "夫人的怪病\ntalk %x# welcome.7\n", getoid(me) );
	}
	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s：\n    "+"/quest/word"->get_country_word(me) + "\n",get_name()) +
		tmp +
		ESC"离开");
	else
		more_look_menu( who, sprintf( "%s：\n    %s\n", get_name(), "/quest/word"->get_country_word(me) ) );
	
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,i,size,p,amount;
        object who,item, *inv;     
       	string *nTmp,tmp;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 1:
        	if ( who->get_level() >=45 && !who->get_legend(TASK_12,1) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    前段日子我听说，郑国渠那里阴风阵阵，怨气冲天，百姓被弄的惶恐不安。\n    我想应该是一种叫怨魔的妖怪在作祟，你前去打探一下，如果发现了他，那就干掉他吧！\n"ESC"接受任务\ntalk %x# welcome.2\n"ESC"离开", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_12,1) && !who->get_legend(TASK_12,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    看来以后得绕着郑国渠走了，免得自己性命不保。\n"ESC"离开", me->get_name()));
		else if ( who->get_legend(TASK_12,2) && !who->get_legend(TASK_12,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    这下百姓可以放心的从那里经过，不用再担心了。\n"ESC"完成任务\ntalk %x# welcome.3\n"ESC"离开", me->get_name(),getoid(me)));

        	break;
	case 2:
        	if( who->get_level() >=45 && !who->get_legend(TASK_12,1) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_12,1);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"燕国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,1,"郑国渠的阴风" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"郑国渠的阴风");
        	}
        	break;       
        case 3:
        	if ( who->get_legend(TASK_12,2) && !who->get_legend(TASK_12,3) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/61007",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_12,3);
			who->add_exp(4500);
			who->add_potential(180);
			who->add_cash(4000);
			send_user(who,"%c%s",';',"郑国渠的阴风 经验 4500 潜能 180 金钱 4000 荷包蛋图纸 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,1,"" );
        	}
        	break;   
	case 4:
        	if( who->get_level() >=45 && !who->get_legend(TASK_12,25) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_12,25);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"燕国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,9,"河道冤魂" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"河道冤魂");
        	}
        	break;       
        case 5:
        	if ( who->get_legend(TASK_12,26) && !who->get_legend(TASK_12,27) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_12,27);
			who->add_exp(5300);
			who->add_potential(210);
			who->add_cash(4500);
			send_user(who,"%c%s",';',"河道冤魂 经验 5300 潜能 210 金钱 4500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,9,"" );
        	}
        	break; 
        case 6:
        	if ( who->get_level() >=45 && !who->get_legend(TASK_12,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    前几天，有个风水先生经过郑国渠时告诉我，看似平静的表面下其实笼罩着团团迷雾，郑国渠一带怨气冲天，是由于冤魂聚集所致，而这些冤魂肯定是被夜宿鬼召唤来的。\n    你前去将夜宿鬼除掉吧，以免他召唤更多的鬼魂来害人！\n"ESC"接受任务\ntalk %x# welcome.4\n"ESC"离开", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_12,25) && !who->get_legend(TASK_12,26) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    这真是可怕，不知那里将会发生什么事。以后路过那里还是小心为妙。\n"ESC"离开", me->get_name()));
		else if ( who->get_legend(TASK_12,26) && !who->get_legend(TASK_12,27) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    %s真是为百姓做了件大好事啊！\n"ESC"完成任务\ntalk %x# welcome.5\n"ESC"离开", me->get_name(),NPC_RANK_D->get_respect_2(who),getoid(me)));
        	
        	break;  
        case 7:
        	if ( who->get_level() >=50 && !who->get_legend(TASK_15,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    夫人生这病有些年头了，一直无法治好，不犯病时跟正常人一样，可一犯起病来谁都无法控制呀！我最近得到个药方，想试试有没有效果，但是很多药都没有，你帮帮忙，去找药店老板要3颗灵芝好吗？\n"ESC"接受任务\ntalk %x# welcome.8\n"ESC"离开", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_15,7) && !who->get_legend(TASK_15,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    夫人恐怕又得发病了，请你加快速度行吗？\n"ESC"离开", me->get_name()));
		else if (who->get_legend(TASK_15, 9) && !who->get_legend(TASK_15, 10))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    听那药店老板说，他已经叫你去燕长城找了，难道你还没找到吗？\n"ESC"离开", me->get_name()));
		else if (who->get_legend(TASK_15, 10) && !who->get_legend(TASK_15, 11))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    真是太感谢你了，可那药方上说还需要5棵黄连，这可如何是好！\n"ESC"完成任务\ntalk %x# welcome.9\n"ESC"离开", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_15,11) && !who->get_legend(TASK_15,12) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    现在还缺5棵黄连，你能再帮帮我吗？去长白山找5棵黄连来。\n"ESC"接受任务\ntalk %x# welcome.10\n"ESC"离开", me->get_name(),getoid(me)));
		else if (who->get_legend(TASK_15, 12) && !who->get_legend(TASK_15, 13))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    虽然黄连比灵芝要好找得多，但是还是挺困难的，辛苦你了。\n"ESC"离开", me->get_name()));
		else if (who->get_legend(TASK_15, 13) && !who->get_legend(TASK_15, 14))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    真是太感谢你了！你是我们家的大恩人！\n"ESC"完成任务\ntalk %x# welcome.11\n"ESC"离开", me->get_name(),getoid(me)));		
        	break; 
	case 8:
        	if( who->get_level() >=50 && !who->get_legend(TASK_15,7) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_15,7);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"燕国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,30,"夫人的怪病（1）" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"夫人的怪病（1）");
        	}
        	break; 
	case 9:
        	if(who->get_legend(TASK_15, 10) && !who->get_legend(TASK_15, 11))
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"灵芝",3) != 1 )
        			return;
			TASK_LEGEND_D->give_item(who,"item/product/62039",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_15,11);
        		who->delete_save_2("frlingzhi");
			who->add_exp(5000);
			who->add_potential(200);
			who->add_cash(3500);
			send_user(who,"%c%s",';',"夫人的怪病（2） 经验 5000 潜能 200 金钱 3500 银蛇剑图纸 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,31,"" );
        		me->do_welcome(7);
        	}
        	break; 
	case 10:
        	if( who->get_legend(TASK_15,11) && !who->get_legend(TASK_15,12) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_15,12);
        		who->delete_save_2("frhuanglian");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"燕国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,32,"夫人的怪病（3）" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"夫人的怪病（3）");
        	}
        	break; 
	case 11:
        	if(who->get_legend(TASK_15, 13) && !who->get_legend(TASK_15, 14))
        	{
        		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),50,HEAD_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
        		if (TASK_LEGEND_D->check_task_item(who,"黄连",5) != 1 )
        			return;
			TASK_LEGEND_D->give_item(who,tmp,1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_15,14);
        		who->delete_save_2("frhuanglian");
			who->add_exp(8500);
			who->add_potential(500);
			who->add_cash(8600);
			send_user(who,"%c%s",';',sprintf("夫人的怪病（3） 经验 8500 潜能 500 金钱 8600 %s 1",tmp->get_name()));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,32,"" );
        	}
        	break; 
        }
}