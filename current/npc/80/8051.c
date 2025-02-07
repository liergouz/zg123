
// �Զ����ɣ�/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

void do_task_start();
void do_task_cancel();

// ��������ȡ��������
int get_char_picid() { return 5401; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("��ܼ�");
        set_city_name("���");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ])); 
//	set("level",49);
//	set("legend",({32*13+1}));
	set("mpLegend",([45:({32*13+1}),]));
	set("mpLegend2",([45:({32*13+3}),]));
        setup();
}

void do_look( object who )
{
	object me = this_object();
	string tmp="";
	
	if ( who->get("escort.finish") == 1 )
	{
		TASK_ESCORT_D->do_look_2( who, me ); 
		return ;
	}
        if(     who->get_quest("escort.flag")    // ��������
        &&      who->get_quest("escort.leader") == 1    // �ӳ����
        &&      who->get_quest("escort.name") == get_name() 
        && 	who->get_quest("escort.city")+"��" == get_city_name() )    // �Ҷ�����
        {
		TASK_ESCORT_D->do_look_2( who, me ); 
		return ;
	}        
	
        tmp += CHAIN_D->get_chain_menu(who,me);
	if ( ( who->get_level() >= 45 && !who->get_legend(TASK_13,1) ) || ( who->get_legend(TASK_13,1) && !who->get_legend(TASK_13,3) ) )
		tmp += sprintf(ESC HIY "��������\ntalk %x# welcome.1\n",getoid(me));
			
	send_user(who,"%c%s",':',sprintf( "%s��\n    �ܹ��ľ����ھ�ξ������ͷ���ո�ǿ�����Ժ�ˬ������һ���ú���\n", get_name(),  ) 
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
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_level() >= 45 && !who->get_legend(TASK_13,1) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���¿ɻ��˴����ˣ��Ұѽ�������ϲ�ı����Ū���ˣ������ɱͷ����������Ǻð���\n    �Ҽǵ��Ҵ�֣�����������û�����ˣ���ʱ����ȥϸϸ���ˣ��ɾ���û�ҵ���������Ҳ���ܷŹ����һ˿ϣ������ȥ�������Ұɣ��Ǳ���б�����\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_13,1) && !who->get_legend(TASK_13,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������������������ܰ���\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_13,2) && !who->get_legend(TASK_13,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������ŵ��ģ������Ƿ������ˡ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        		
        	break;
	case 2:
        	if( who->get_level() >=45 && !who->get_legend(TASK_13,1) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_13,1);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,11,"��������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��������");
        	}
        	break;       
        case 3:
        	if ( who->get_legend(TASK_13,2) && !who->get_legend(TASK_13,3) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"������",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_13,3);
			who->add_exp(5400);
			who->add_potential(190);
			who->add_cash(4900);
			send_user(who,"%c%s",';',"�������� ���� 5400 Ǳ�� 190 ��Ǯ 4900");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,11,"" );
        	}
        	break;   
        }
}