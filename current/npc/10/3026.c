
// �Զ����ɣ�/make/npc/make-collect

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <music.h>
#include <equip.h>

inherit OFFICER;

void do_task();

// ��������ȡ��������
int get_char_picid() { return 5505; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("��ǿ");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      
//        set("level",41);
//        set("legend",({32*11+1}));    
	set("mpLegend",([40:({32*11+1})]));
	set("mpLegend2",([0:({32*46+20,32*46+23,}),40:({32*11+3,32*11+10}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
        tmp += CHAIN_D->get_chain_menu(who,this_object());
        if ( (who->get_level() >= 40 && !who->get_legend(TASK_11,1)) || (who->get_legend(TASK_11,1)&&!who->get_legend(TASK_11,3)) ) 
		tmp += sprintf(ESC HIY "Ѱ������\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( (who->get_legend(TASK_11,3) && !who->get_legend(TASK_11,4)) || (who->get_legend(TASK_11,4)&&!who->get_legend(TASK_11,5)) ) 
		tmp += sprintf(ESC HIY "��ȥ����\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( who->get_legend(TASK_11,9)&&!who->get_legend(TASK_11,10) ) 
		tmp += sprintf(ESC HIY "��ȥ����\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( who->get_legend(TASK_46,19)&&!who->get_legend(TASK_46,20) ) 
		tmp += sprintf(ESC HIY "�������\ntalk %x# welcome.6\n",getoid(this_object())); 
         if ( who->get_legend(TASK_46,20)&&!who->get_legend(TASK_46,23) ) 
		tmp += sprintf(ESC HIY "Ѱ������\ntalk %x# welcome.6\n",getoid(this_object())); 
         if ( who->get_legend(TASK_46,23)&&!who->get_legend(TASK_46,24) ) 
		tmp += sprintf(ESC HIY "ת���ź�\ntalk %x# welcome.6\n",getoid(this_object())); 
 
        send_user( who, "%c%s", ':', sprintf( "%s��\n    ��ֻ��һ������������Ҿ�ƶ����һ��żȻ�������ع��ı���С�㣬����������һ��ǰ��δ�е������밮����\n", get_name())
        + tmp +
        ESC"�뿪"
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
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Դ��Ҽ�������С��󣬾�һֱ��˼ĺ�룬���μҾ�ƶ�������͵㶫��������С�����ҵ����⣬����ʵ��û��ʲô���õó��ֵġ�\n    ��һֱ��������һ���������������㿴�������ӣ���֪�����𣬲�������˵��������Ϻ��з�����У�����ȥ������һ������\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_11,1) && !who->get_legend(TASK_11,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���û������Ǳ���С��������������ʶ�أ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_11,2) && !who->get_legend(TASK_11,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��л�������ҵ��˺��ʵ��������һ���������ܽ����������أ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_11,3) && !who->get_legend(TASK_11,4) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������������ĳ����·���û�У����ᰡ���������������ȥ���������\n"ESC"��������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_11,4) && !who->get_legend(TASK_11,5) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����С����ô�ش��ҵģ�����ȥ��������\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_11,9) && !who->get_legend(TASK_11,10) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����������������̫�����ˣ�����С���Ȼ��������������������ĸ�㣡\n"ESC"�������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));

        	break;
        case 2:
        	if(who->get_level() >= 40 && !who->get_legend(TASK_11,1))
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_11,1);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,3,"�����ع���1��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�����ع���1��");
        	}
        	break;
       case 3:
        	if ( who->get_legend(TASK_11,2) && !who->get_legend(TASK_11,3) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"��������",1) != 1 )
        			return;
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_11,3);
			who->add_exp(4500);
			who->add_potential(140);
			who->add_cash(3500);
			send_user(who,"%c%s",';',"�����ع���1�� ���� 4500 Ǳ�� 140 ��Ǯ 3500");
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
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,4,"�����ع���2��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�����ع���2��");
        	}
        	break;
       case 5:
        	if ( who->get_legend(TASK_11,9) && !who->get_legend(TASK_11,10) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"���",1) != 1 )
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
			send_user(who,"%c%s",';',sprintf("�����ع���4�� ���� 4300 Ǳ�� 138 ��Ǯ 3800 %s 1",tmp->get_name()));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,6,"" );
        	}
        	break;    
        case 6:
        	if ( who->get_legend(TASK_46,19)&&!who->get_legend(TASK_46,20) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����׳ʿ����˵�Ƕ��չ�����ھ�Ȼ�����ˣ������������ѣ����ж񱨣���л׳ʿΪ�ұ�����������ء�����ϧ�ҵĵܵ���Ҳ�ز����ˣ���Ҫ�������������ͷ���������ܵ�ԩ�꣡\n"ESC"�������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_46,20)&&!who->get_legend(TASK_46,21) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������Ƕ�˵������ҵ�Ҳ��֪һ������Ϊ����Ҹ�������ͬһս����ս����Ȼ���Ӳ�͸¶�Լ�����������ս���ͣ�ȴ���Ų����ϼ�ָ�����ɱ���˸����ӻ�ɽ�У��Ҹ���������������ȴ��С������֪���˼Ҵ��Ľ����飬��Ȼ������֪���кδ��ã�����ȴҲС���ղأ��Ƕ�����������鼸���۾��Ź⣬�����ҵĸ�������ս�������ֵ�Ҳ���䵽�ˣ���֪��������ҵ����ǣ����������˽����飬�ҵܵܲ������ϸ汻������ɱ���������ʹ������ҽ���ʲô������ �ҵȴ���û�м�������ε�֪��չ��ʹ��̾���ƽ����������ɧ�ž��񣬶���������Ŀ಻���ԡ������������ȥ���ҵļҴ�����������Ҳ�Դ�ʧȥ��Ӱ�������Ƕ�����������ǰ����һ���ӳ�����Сආ�˵��˳���������������ϲ�����������ǻ��������ǽ�����Ͳ���ĳ�����������׳ʿ����һ�ˣ�����Ѱ�ش���������\n"ESC"��������\ntalk %x# welcome.8\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_46,21)&&!who->get_legend(TASK_46,22) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Ī�ǽ����龹Ȼ��ľʹ���ʧ��ô���ҳ�ǿ��ĶԲ���̼ҵ����氡��\n"ESC"�뿪", me->get_name(),));
		else if ( who->get_legend(TASK_46,22)&&!who->get_legend(TASK_46,23) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������������ǳ̼ҵĴ�����ģ�����к��µ�ƾ�Ը��������ϵ�ɽ�»�Ҳ������ü��\n"ESC"�������\ntalk %x# welcome.9\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_46,23)&&!who->get_legend(TASK_46,24) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ƽ�����������ѳ�������ֿ��԰�����ҵ�ˣ��ҽ��������������д�����£��ͷ�׳ʿ�͸�������ʷ���ˣ��������İɡ�\n"ESC"��������\ntalk %x# welcome.10\n"ESC"�뿪", me->get_name(),getoid(me)));
			
        	break;
        case 7:
        	if( who->get_legend(TASK_46,19)&&!who->get_legend(TASK_46,20) )
        	{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_46,20);
			who->add_exp(92000);
			who->add_potential(980);
			who->add_cash(93000);
			send_user(who,"%c%s",';',"ƽ��֮��3 ���� 92000 Ǳ�� 980 ��Ǯ 93000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,71,"" );
			me->do_welcome(6);
        	}
        	break;
        case 8:
        	if ( who->get_legend(TASK_46,20)&&!who->get_legend(TASK_46,21) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_46,21);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,72,"ƽ��֮��4" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ƽ��֮��4");
       		}
        	break;
        case 9:
        	if( who->get_legend(TASK_46,22)&&!who->get_legend(TASK_46,23) )
        	{
			if (TASK_LEGEND_D->check_task_item(who,"������",1) != 1 )
        			return;
        		TASK_LEGEND_D->give_item(who,"item/product/64187",1);
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_46,23);
			who->add_exp(92000);
			who->add_potential(980);
			who->add_cash(93000);
			send_user(who,"%c%s",';',"ƽ��֮��4 ���� 92000 Ǳ�� 980 ��Ǯ 93000 ����ս��ͼֽ 1");
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
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,73,"ƽ��֮��5" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ƽ��֮��5");
       		}
        	break;
        }
}