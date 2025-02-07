#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <equip.h>

inherit OFFICER;

void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 5404; }

// ���������촦��
void create()
{
        set_name("��ͭ");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      
	set("mpLegend2",([0:({32*36+30,32*37+9,32*37+12,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
        if ( who->get_legend(TASK_36,29) && !who->get_legend(TASK_36,30) ) 
		tmp += sprintf(ESC HIY "Ф����\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( (who->get_legend(TASK_36,30) && !who->get_legend(TASK_37,7)) || ( who->get_legend(TASK_37,7) && !who->get_legend(TASK_37,9) ) )
		tmp += sprintf(ESC HIY "��ʬ��\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( (who->get_legend(TASK_37,9) && !who->get_legend(TASK_37,10)) || ( who->get_legend(TASK_37,10) && !who->get_legend(TASK_37,12) ) )
		tmp += sprintf(ESC HIY "����\ntalk %x# welcome.1\n",getoid(this_object())); 

        send_user( who, "%c%s", ':', sprintf( "%s��\n    �����أ��ҶԲ���Ф��硢��㰡��������û���չ˺������������Ǻð���\n", get_name())
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
        int flag,i,size,p,amount;
        object who,item, *inv;     
        string *nTmp,tmp;
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_legend(TASK_36,29) && !who->get_legend(TASK_36,30) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Ф������˽�ʬ���ˣ��Ҷ��ձ��ߵ����и����ε����������Ҹ�����ƫ���������䷽̫�����ˣ�������������ձ������������磬����������֣�Ҳ�������Ÿ���㰡��\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_36,30) && !who->get_legend(TASK_37,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Ф��������˽�ʬ������ȷ��˵��������ʬҧ��һ�ڣ������Ѿ��ǽ�ʬ�ˣ����ֽ�ʬ��������ͨ�Ľ�ҩ�ܽ�ģ�����Ҫ��ʬ�����ϵĽ�ʬ�ۣ������ֽ�ʬ��ֻ��ɱ����ʬ�������õ������ڽ�ʬ�����ڹ���С�������º����㴩�������ž����ҵ����������ϸ�������Ժ����������������ɡ�\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_37,7) && !who->get_legend(TASK_37,8) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��Ҳ�ò����𣿰�����Ҫ�ǾȲ���Ф��磬��Ҳ������ˣ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_37,8) && !who->get_legend(TASK_37,9) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    л��л�أ������õ���ʬ���ˣ�����������ѽ���ˣ�Ф���Ҳ����Իָ��ˣ�\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_37,9) && !who->get_legend(TASK_37,10) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Ф���Ĳ������ڻ������������Ʒ���ܽⶾ��ȥ�����Ÿ����ҵ����зۡ�Ŵ�ס����͵�����\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_37,10) && !who->get_legend(TASK_37,11) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Ф������ձ����ֶ���ĥ����ȥ����������ôһ�㶼���ż��أ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_37,11) && !who->get_legend(TASK_37,12) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ˣ����¾߱���ֻǷ���磬�������鶼�����Ұɣ������ڿ��Բ��ر�����ô����������ˡ�\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));

        	break;

        case 2:
        	if ( who->get_legend(TASK_36,29) && !who->get_legend(TASK_36,30) ) 
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_36,30);
			who->add_exp(36000);
			who->add_potential(600);
			who->add_cash(40000);
			send_user(who,"%c%s",';',"Ф����2�� ���� 36000 Ǳ�� 600 ��Ǯ 40000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,61,"" );
			me->do_welcome(1);
        	}
        	break;   
	case 3:
        	if ( who->get_legend(TASK_36,30) && !who->get_legend(TASK_37,7) )
        	{
          		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
          		who->set_legend(TASK_37,7);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_DONGHAIDAO,"������" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_DONGHAIDAO,1,"Ф����3��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"Ф����3��");
        	}
        	break;
        case 4:
        	if ( who->get_legend(TASK_37,8) && !who->get_legend(TASK_37,9) ) 
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"��ʬ��",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_37,9);
			who->add_exp(45000);
			who->add_potential(655);
			who->add_cash(44000);
			send_user(who,"%c%s",';',"Ф����3�� ���� 45000 Ǳ�� 655 ��Ǯ 44000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_DONGHAIDAO,1,"" );
			me->do_welcome(1);
        	}
        	break;
	case 5:
        	if ( who->get_legend(TASK_37,9) && !who->get_legend(TASK_37,10) )
        	{
          		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
          		who->set_legend(TASK_37,10);
			who->delete_save("mtxianxf");
			who->delete_save("mtnuomi");
			who->delete_save("mtbaohd");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_DONGHAIDAO,"������" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_DONGHAIDAO,2,"Ф����4��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"Ф����4��");
        	}
        	break;
        case 6:
        	if ( who->get_legend(TASK_37,11) && !who->get_legend(TASK_37,12) ) 
        	{
        		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),100,BOOTS_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
        		if (TASK_LEGEND_D->check_task_item(who,"���з�",1) != 1 )
        			return;
        		if (TASK_LEGEND_D->check_task_item(who,"Ŵ��",8) != 1 )
        		{
        			TASK_LEGEND_D->give_item(who,"item/98/0174",1);
        			return;
        		}
        		if (TASK_LEGEND_D->check_task_item(who,"���͵�",1) != 1 )
        		{
        			TASK_LEGEND_D->give_item(who,"item/98/0174",1);
        			TASK_LEGEND_D->give_item(who,"item/98/0175",8);
        			return;
        		}		
			TASK_LEGEND_D->give_item(who,tmp,1);
			who->delete_save("mtxianxf");
			who->delete_save("mtnuomi");
			who->delete_save("mtbaohd");
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_37,12);
			who->add_exp(210000);
			who->add_potential(2300);
			who->add_cash(210000);
			send_user(who,"%c%s",';',sprintf("Ф����4�� ���� 210000 Ǳ�� 2300 ��Ǯ 210000 %s 1",tmp->get_name()));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_DONGHAIDAO,2,"" );
			me->do_welcome(1);
        	}
        	break;
        }
}