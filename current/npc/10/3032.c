
// �Զ����ɣ�/make/npc/make-collect

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <music.h>
#include <equip.h>

inherit OFFICER;

void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 5501; }

// ���������촦��
void create()
{
        set_name("��ҩʦ");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      
 	set("mpLegend",([60:({32*19+1}),]));
 	set("mpLegend2",([0:({32*36+8,32*46+14,32*46+17,32*46+27,32*46+30,32*47+5,}),60:({32*19+6,32*19+9,32*19+12,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
        tmp += CHAIN_D->get_chain_menu(who,this_object());
        if ( (who->get_level() >= 60 && !who->get_legend(TASK_19,1)) || (who->get_legend(TASK_19,1)&&!who->get_legend(TASK_19,2)) ) 
		tmp += sprintf(ESC HIY "Ѱ�Ҵ��«����\ntalk %x# welcome.1\n",getoid(this_object())); 
 	if (who->get_legend(TASK_19,5)&&!who->get_legend(TASK_19,6))
 		tmp += sprintf(ESC HIY "Ѱ�Ҵ��«����\ntalk %x# welcome.1\n",getoid(this_object())); 
 	if ((who->get_legend(TASK_19,6)&&!who->get_legend(TASK_19,7)) || (who->get_legend(TASK_19,7)&&!who->get_legend(TASK_19,9)) )
 		tmp += sprintf(ESC HIY "���������\ntalk %x# welcome.1\n",getoid(this_object())); 
 	if ((who->get_legend(TASK_19,9)&&!who->get_legend(TASK_19,10)) || (who->get_legend(TASK_19,10)&&!who->get_legend(TASK_19,12)) )
 		tmp += sprintf(ESC HIY "�Ҿ���\ntalk %x# welcome.1\n",getoid(this_object())); 
	if ( who->get_legend(TASK_36,6) && !who->get_legend(TASK_36,8) )
		tmp += sprintf(ESC HIY "��ҩ\ntalk %x# welcome.8\n",getoid(this_object()));
	if ( who->get_legend(TASK_36,8) && !who->get_legend(TASK_36,9) )
		tmp += sprintf(ESC HIY "������ʯ\ntalk %x# welcome.8\n",getoid(this_object()));
        if ( who->get_legend(TASK_46,13)&&!who->get_legend(TASK_46,14) ) 
		tmp += sprintf(ESC HIY "̽����Ϣ\ntalk %x# welcome.11\n",getoid(this_object())); 
        if ( who->get_legend(TASK_46,14)&&!who->get_legend(TASK_46,17) ) 
		tmp += sprintf(ESC HIY "ĥ������\ntalk %x# welcome.11\n",getoid(this_object())); 
        if ( who->get_legend(TASK_46,17)&&!who->get_legend(TASK_46,18) ) 
		tmp += sprintf(ESC HIY "�������\ntalk %x# welcome.11\n",getoid(this_object())); 
        if ( who->get_legend(TASK_46,26)&&!who->get_legend(TASK_46,27) ) 
		tmp += sprintf(ESC HIY "�ݷ�֮·\ntalk %x# welcome.16\n",getoid(this_object())); 
        if ( who->get_legend(TASK_46,27)&&!who->get_legend(TASK_46,30) ) 
		tmp += sprintf(ESC HIY "����Ѱ��\ntalk %x# welcome.16\n",getoid(this_object())); 
        if ( who->get_legend(TASK_46,30)&&!who->get_legend(TASK_47,1) ) 
		tmp += sprintf(ESC HIY "ѯ���䷽\ntalk %x# welcome.16\n",getoid(this_object())); 
        if ( who->get_legend(TASK_47,4)&&!who->get_legend(TASK_47,5) ) 
		tmp += sprintf(ESC HIY "����֮ҩ\ntalk %x# welcome.16\n",getoid(this_object())); 
        if ( who->get_legend(TASK_47,5)&&!who->get_legend(TASK_47,6) ) 
		tmp += sprintf(ESC HIY "�������\ntalk %x# welcome.16\n",getoid(this_object())); 
		
        send_user( who, "%c%s", ':', sprintf( "%s��\n    %s\n", get_name(),TASK_COLLECT_D->get_talk_string(1011))
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
	       	if ( who->get_level() >= 60 && !who->get_legend(TASK_19,1) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��˵��һ�ִ��«������װ��ʯ����ô�ֻ࣬��κ�������ë����������ӣ����Ƿ�����Ȥ���������ֵ����ӣ��Ⱥ�«�ֳ������Ҷ�������һ����\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_19,1) && !who->get_legend(TASK_19,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������˲��ֵļ����ǿɾͲ����ˡ�\n"ESC"�뿪", me->get_name()));
       		else if (who->get_legend(TASK_19,5)&&!who->get_legend(TASK_19,6))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����������˴��«���ӣ��������Ľ���׼������ȥ�����أ�����߿����ҿɲ��밴���Ͱ���ּ����²��ܿ������«����������������㡣\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
       		else if (who->get_legend(TASK_19,6)&&!who->get_legend(TASK_19,7))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��˵�س��ǵĹ���˽��һ����������˵�ܹ��߷����֣�������Ҫ�����µ�����һ����ܳ��ɣ��Ҿ�����������������������ɺ�«����ȥ����Ū20�������������������ۿ����ɺ�«����ô���ɵġ�\n"ESC"��������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_19,7) && !who->get_legend(TASK_19,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    û������������������ҿɲ�������Ӳ�����ȥ�������˷�����Щ�����ӡ�\n"ESC"�뿪", me->get_name()));
       		else if (who->get_legend(TASK_19,8)&&!who->get_legend(TASK_19,9))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ۣ�����һ����ȥ�ոս�ˮ�Ϳ�ʼ��Ƥ�ˣ�������ѿ�ˣ�������ˣ���Ҷչ���ˡ����������ɺ�«���Ҿ�Ȼ����Ŀ��������漣����̫�Ҹ��ˡ���\n"ESC"�������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
       		else if (who->get_legend(TASK_19,9)&&!who->get_legend(TASK_19,10))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������ڽ�����ˣ���Ȼ����Ϊ���«�������²�Բ��������Ϲϣ�����һ�̵ֶı����ۣ�Ƥ��úܣ���������֪������Ƥ�ȳ�ǽ����Ҫ�Ǿ�����룬��Ҩˮ��ư������ʢЩ���ص�ҩ��Ҳ�������߼ۣ� ֻ��Ҫ������õ��п������ܻ���Ҫһ�ַ����ľ��ӣ���˵�س��ǵĵ��ܱ����и־��ӣ���ȥ���ҿ���\n"ESC"��������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_19,10) && !who->get_legend(TASK_19,11) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��˵�����Ҫ�ȵ���«����ʱ���õ��ţ����㻹����������ĺã�\n"ESC"�뿪", me->get_name()));
       		else if (who->get_legend(TASK_19,11)&&!who->get_legend(TASK_19,12))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    лл���������ӣ����Ǹ���ı��ꡣ\n"ESC"�������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
       			
        	break;
	case 2:
        	if ( who->get_level() >= 60 && !who->get_legend(TASK_19,1) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_19,1);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,54,"���«��1��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���«��1��");
        	}
        	break;       
        case 3:
        	if ( who->get_legend(TASK_19,5) && !who->get_legend(TASK_19,6) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"���«����",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_19,6);
			who->add_exp(3830);
			who->add_potential(165);
			who->add_cash(3560);
			send_user(who,"%c%s",';',"���«��3�� ���� 3830 Ǳ�� 165 ��Ǯ 3560");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,10,"" );
       			me->do_welcome(1);
       		}
        	break;
	case 4:
        	if (who->get_legend(TASK_19,6)&&!who->get_legend(TASK_19,7))
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_19,7);
        		who->delete_save_2("teshunitu");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,18,"���«��4��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���«��4��");
        	}
        	break;  
        case 5:
        	if ( who->get_legend(TASK_19,8) && !who->get_legend(TASK_19,9) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"��������",20) != 1 )
        			return;
        		TASK_LEGEND_D->give_item(who,"item/product/65063",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_19,9);
        		who->delete_save_2("teshunitu");
			who->add_exp(6000);
			who->add_potential(190);
			who->add_cash(3700);
			send_user(who,"%c%s",';',"���«��4�� ���� 6000 Ǳ�� 190 ��Ǯ 3700 ��������ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,18,"" );
       			me->do_welcome(1);
       		}
        	break;
	case 6:
        	if (who->get_legend(TASK_19,9)&&!who->get_legend(TASK_19,10))
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_19,10);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,19,"���«��5��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���«��5��");
        	}
        	break;  
        case 7:
        	if ( who->get_legend(TASK_19,11) && !who->get_legend(TASK_19,12) )
        	{
        		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),60,WEAPON_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
        		if (TASK_LEGEND_D->check_task_item(who,"����",1) != 1 )
        			return;
			TASK_LEGEND_D->give_item(who,tmp,1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_19,12);
			who->add_exp(10000);
			who->add_potential(680);
			who->add_cash(15000);
			send_user(who,"%c%s",';',sprintf("���«��5�� ���� 10000 Ǳ�� 680 ��Ǯ 15000 %s 1",tmp->get_name()));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,19,"" );
       		}
        	break;
        case 8:
	        if ( who->get_legend(TASK_36,6) && !who->get_legend(TASK_36,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n   �ţ��������Ҹ�ʲô���������о����䷽��û�����㣬�߿��߿���\n"ESC"�뿪", me->get_name()));
	        else if ( who->get_legend(TASK_36,7) && !who->get_legend(TASK_36,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������ʦ������̫��æ�ˣ�Ҳ�չ����������ո�ʦ�������������龧ʯ�������䷽������˼��������λ���˹�ˣ�ȴԭ���������ｨ�����������д󼪣�������һ�ᣬ����ȥ��Ϥһ���䷽���ܿ�Ϳ��Կ�¯���ˡ������С���ԭ������ͷһ�����������������ͨ��ͨ������ͣ����������Ѿ����ﻢ���£�����ѡ���������ɡ�����\n"ESC"�������\ntalk %x# welcome.9\n"ESC"�뿪", me->get_name(),getoid(me)));
	        else if ( who->get_legend(TASK_36,8) && !who->get_legend(TASK_36,9) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������Ϸ��Ȼ�����ˣ��ղ��������Բ���һ�ԣ���˵�ҿ��Ŵ󼪣���Ȼ��ˣ������ҿɵ�лл������ͻȻһ������״���ȿȣ��������Ϸ�������������������ʵ��ʦ�ֵ������ֶζ��ѣ���ʵ�أ����������ʱ��������ϣ�Ҳ���������������٣�������������������һ��֪����λ�������Ǩ�ɣ��Ǻǣ�һ�����Ὣ�Ϸ�ͬ��һ�𳶽��������֮��ɣ���˵�Ϸ�Զ���ع������������⣬���ȥ�����ʱ����ܻᱻ����Ǩ���Դ��ء��ٺ٣�ϣ�����Ǻ�����졣\n"ESC"��������\ntalk %x# welcome.10\n"ESC"�뿪", me->get_name(),getoid(me)));

		break;
	case 9:
        	if ( who->get_legend(TASK_36,7) && !who->get_legend(TASK_36,8) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"��ʯ��",5) != 1 )
        			return;
        		if (TASK_LEGEND_D->check_task_item(who,"��ʯ",7) != 1 )
        		{
				TASK_LEGEND_D->give_item(who,"item/98/0165",3); 
        			return ;
        		}
        		if (TASK_LEGEND_D->check_task_item(who,"�ۻ�",3) != 1 )
        		{
				TASK_LEGEND_D->give_item(who,"item/98/0165",5); 
				TASK_LEGEND_D->give_item(who,"item/98/0166",7); 
        			return ;
        		}
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_36,8);
        		who->delete_save("qwgushihui");
        		who->delete_save("qwcishi");
        		who->delete_save("qwxionghuang");
			who->add_exp(39000);
			who->add_potential(650);
			who->add_cash(37000);
			send_user(who,"%c%s",';',"������ʯ��3�� ���� 39000 Ǳ�� 650 ��Ǯ 37000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,52,"" );
			me->do_welcome(12);
        	}
        	break;	
	case 10:
        	if ( who->get_legend(TASK_36,8) && !who->get_legend(TASK_36,9) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;        		
			TASK_LEGEND_D->give_item(who,"item/98/0161",1);
          		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
          		who->set_legend(TASK_36,9);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,89,"������ʯ��4��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"������ʯ��4��");
        	}
        	break;
        case 11:
        	if ( who->get_legend(TASK_46,13)&&!who->get_legend(TASK_46,14) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��Ȼ�������˶��������Щ��ɱ��������Ȼ���ҵȶ���С�������֪������ͱ���ǲ�����ˡ��ҽ��컹�м������˵Ĳ��ˣ����Ƕ���Ҫ�����������ȥ��\n"ESC"�������\ntalk %x# welcome.12\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_46,14)&&!who->get_legend(TASK_46,15) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ˣ���ȷ�������Ҫ������£����������Ǻ����������ȥ�ɣ�����¿ɲ������˭���ܵ��˵ģ�Ҫô�����ȥ����������ɱ30�������30��ǹ�꣬�����ٿ��ǿ��ǣ��������Ϊ��ֵ�þͲ�Ҫȥ�ˡ�\n"ESC"��������\ntalk %x# welcome.13\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_46,15)&&!who->get_legend(TASK_46,16) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ֻ�Ǻ���ɣ��ǾͲ�Ҫ���������ˣ������ʲô��û��˵����\n"ESC"�뿪", me->get_name(),));
		else if ( who->get_legend(TASK_46,16)&&!who->get_legend(TASK_46,17) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������У����������������������ܹ�ƽ���ⳡ���ҵ������ڳ����ˣ�ϣ���㲻Ҫ���Ϸ�ʧ����\n"ESC"�������\ntalk %x# welcome.14\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_46,17)&&!who->get_legend(TASK_46,18) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ƽ�������̾���һ�����չ�壬���Ǹ��ųߴ󺺣���ʹһ�Իƽ�ﵣ�����һ������������������һ���ӷ��࣬��������������в���ʱʱ�����������ҽ��ᣬ���踾�棬���з��������������ˣ���Χ�����Ƶ��������������ϸ澹Ȼ��֪Ϊ�α�����֪��������������Ϊ���Σ���״�Ҳ��̶ã��Դ����˶�����������Ҫ���ǿ���һ������������һ������գ��Ϸ�Ϊ���Ϲ�ͷ���޶�������Ҳ�϶ϲ��Ҹ�����ģ���ǰ������ɱ��չ�壬������Сආ���Ȼ��һ���ɢ�����Ҽ�ס��δɱ��֮ǰ���򲻿����ټ��Ϸ򣬷����Ϸ��������ɱ��֮������ɱ��֮����ȥ֪ͨ��ǿ�����ĵܾܵ��Ǳ�չ���ɱ���ġ�\n"ESC"��������\ntalk %x# welcome.15\n"ESC"�뿪", me->get_name(),getoid(me)));
			
        	break;
        case 12:
        	if( who->get_legend(TASK_46,13)&&!who->get_legend(TASK_46,14) )
        	{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_46,14);
			who->add_exp(89000);
			who->add_potential(950);
			who->add_cash(91000);
			send_user(who,"%c%s",';',"ƽ��֮��1 ���� 89000 Ǳ�� 950 ��Ǯ 91000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,69,"" );
			me->do_welcome(11);
        	}
        	break;
        case 13:
        	if ( who->get_legend(TASK_46,14)&&!who->get_legend(TASK_46,15) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->delete_save("qysjianhun");
        		who->delete_save("qysqianhun");
        		who->set_legend(TASK_46,15);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,70,"ƽ��֮��2" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ƽ��֮��2");
       		}
        	break;
        case 14:
        	if( who->get_legend(TASK_46,16)&&!who->get_legend(TASK_46,17) )
        	{
        		who->delete_save("qysjianhun");
        		who->delete_save("qysqianhun");
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_46,17);
			who->add_exp(88000);
			who->add_potential(910);
			who->add_cash(93000);
			send_user(who,"%c%s",';',"ƽ��֮��2 ���� 88000 Ǳ�� 910 ��Ǯ 93000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,70,"" );
			me->do_welcome(11);
        	}
        	break;
        case 15:
        	if ( who->get_legend(TASK_46,17)&&!who->get_legend(TASK_46,18) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_46,18);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,71,"ƽ��֮��3" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ƽ��֮��3");
       		}
        	break;
        case 16:
        	if ( who->get_legend(TASK_46,26)&&!who->get_legend(TASK_46,27) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ̫���ˣ���������������Ѱҩ�ˣ���ȵ��ҿ�������Щ������\n"ESC"�������\ntalk %x# welcome.17\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_46,27)&&!who->get_legend(TASK_46,28) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����Ϊ����Ӯ�����Ƶ�ҩ������һζ�����ݣ��Ҵ�����ʱ��֪���Ƕ����˻���������ɣ������������ӵ������У�����������������Ľ���Ļ����Լ���λ�����ʺϴ���ݵ����������ܰ���ȡ��ô�����ﻷ���ն��Ϸ�ʵ�ڲ���ǰȥ��Ҫ������û�н�ȥ�Ϲ�ͷ�ͽ����ˡ�\n"ESC"��������\ntalk %x# welcome.18\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_46,28)&&!who->get_legend(TASK_46,29) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����عܼҲ����Ĵ����ĵ�ҩ��ֻ�Ƿ��������˸����Ϻ�������ߺߣ���Ҫ���عܼҸϽ����һ��ˣ�Ҫô�Ҿ��ϸ������\n"ESC"�뿪", me->get_name(),));
        	else if ( who->get_legend(TASK_46,29)&&!who->get_legend(TASK_46,30) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ǻǣ��عܼҹ�Ȼ���˸��������˰��������ˣ��Ժ����������������ҡײƭ����������\n"ESC"�������\ntalk %x# welcome.19\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_46,30)&&!who->get_legend(TASK_47,1) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ĺ���Ϸ����֪�����ѣ�����ҩ��ҩ��Ҳ��Ϊ�˽⣬�Ϸ�Ψ����ʲô���ǲ���֮�����㽫���䷽��������ѯ�����ļ��⣬���������ҡ�\n"ESC"��������\ntalk %x# welcome.20\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_47,4)&&!who->get_legend(TASK_47,5) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ԭ����ˣ��Һ������ʹ��ĺ��ϵܣ�Ҫ����������ȥ�������Ѵ���̰���\n"ESC"�������\ntalk %x# welcome.21\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_47,5)&&!who->get_legend(TASK_47,6) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ĺ��ϵܵ�һζ�㾦֮ҩ�������ڿ��������ɵ���������ˣ��ٵȸ�һ��һҹ��ҩ�Ϳ��Գ�¯����������ĺ��ϵ���л����������¯֮�������������̸��������\n"ESC"��������\ntalk %x# welcome.22\n"ESC"�뿪", me->get_name(),getoid(me)));
 			
        	break; 
        case 17:
        	if( who->get_legend(TASK_46,26)&&!who->get_legend(TASK_46,27) )
        	{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_46,27);
			who->add_exp(98000);
			who->add_potential(1010);
			who->add_cash(91000);
			send_user(who,"%c%s",';',"��ҩ֮·1 ���� 98000 Ǳ�� 1010 ��Ǯ 91000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,74,"" );
			me->do_welcome(16);
        	}
        	break;        	
        case 18:
        	if ( who->get_legend(TASK_46,27)&&!who->get_legend(TASK_46,28) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_46,28);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,75,"��ҩ֮·2" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ҩ֮·2");
       		}
        	break;
        case 19:
        	if( who->get_legend(TASK_46,29)&&!who->get_legend(TASK_46,30) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"������",1) != 1 )
        			return;
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_46,30);
			who->add_exp(89000);
			who->add_potential(990);
			who->add_cash(92000);
			send_user(who,"%c%s",';',"��ҩ֮·2 ���� 89000 Ǳ�� 990 ��Ǯ 92000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,75,"" );
			me->do_welcome(16);
        	}
        	break; 
        case 20:
        	if ( who->get_legend(TASK_46,30)&&!who->get_legend(TASK_47,1) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			TASK_LEGEND_D->give_item(who,"item/98/0232",1);
        		who->set_legend(TASK_47,1);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,76,"��ҩ֮·3" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ҩ֮·3");
       		}
        	break;
        case 21:
        	if( who->get_legend(TASK_47,4)&&!who->get_legend(TASK_47,5) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"�¼���",1) != 1 )
        			return;
        		TASK_LEGEND_D->give_item(who,"item/product/64188",1);
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_47,5);
			who->add_exp(88000);
			who->add_potential(910);
			who->add_cash(93000);
			send_user(who,"%c%s",';',"��ҩ֮·4 ���� 88000 Ǳ�� 910 ��Ǯ 93000 ������װͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,77,"" );
			me->do_welcome(16);
        	}
        	break;        	
        case 22:
        	if ( who->get_legend(TASK_47,5)&&!who->get_legend(TASK_47,6) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_47,6);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,78,"��ҩ֮·5" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ҩ֮·5");
       		}
        	break;
        }
}