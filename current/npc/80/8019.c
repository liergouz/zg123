
// �Զ����ɣ�/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

void do_task_start();
void do_task_cancel();

// ��������ȡ��������
int get_char_picid() { return 5501; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("���");
        set_city_name("�Թ�");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ]));
	set("mpLegend2",([0:({32*14+14,32*43+8,32*43+11,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	object me = this_object();
	string tmp="";
	string *npc_info;
	
	if ( who->get("escort.finish") == 1 )
	{
		TASK_ESCORT_D->do_look_2( who, me ); 
		return ;
	}
	npc_info = who->get_quest("escort.npcinfo");
	if ( who->get_quest("escort.biaowang") && arrayp(npc_info) && 
		npc_info[1] == me->get_name())
		tmp += sprintf(ESC HIG "��������ս\ntalk %x# welcome.21\n",getoid(me));
        else if(     who->get_quest("escort.flag")    // ��������
        &&      who->get_quest("escort.leader") == 1    // �ӳ����
        &&      who->get_quest("escort.name") == get_name() 
        && 	who->get_quest("escort.city")+"��" == get_city_name() )    // �Ҷ�����
        {
		TASK_ESCORT_D->do_look_2( who, me ); 
		return ;
	}        
	
        tmp += CHAIN_D->get_chain_menu(who,me);
	if ( who->get_legend(TASK_14,13) && !who->get_legend(TASK_14,14) )
		tmp += sprintf(ESC HIY "ȡ��\ntalk %x# welcome.1\n",getoid(me));
	if ( who->get_legend(TASK_43,7) && !who->get_legend(TASK_43,8) )
		tmp += sprintf(ESC HIY "���֪����\ntalk %x# welcome.3\n",getoid(me));
	if ( who->get_legend(TASK_43,8) && !who->get_legend(TASK_43,11) )
		tmp += sprintf(ESC HIY "�����в\ntalk %x# welcome.3\n",getoid(me));
	if ( who->get_legend(TASK_43,11) && !who->get_legend(TASK_43,12) )
		tmp += sprintf(ESC HIY "Ѱ������\ntalk %x# welcome.3\n",getoid(me));
			
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
	       	if ( who->get_legend(TASK_14,13) && !who->get_legend(TASK_14,14) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����������Խ������ǣ�������Բ���ֱ�����绷����������ྭ���������ɣ��Ҵ����Ի����˺������ʷ�����������������ȥ��\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        		
        	break;
    
        case 2:
        	if ( who->get_legend(TASK_14,13) && !who->get_legend(TASK_14,14) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/62041",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_14,14);
			who->add_exp(8000 );
			who->add_potential(480);
			who->add_cash(7000);
			send_user(who,"%c%s",';',"���ǣ�3�� ���� 8000 Ǳ�� 480 ��Ǯ 7000 �����ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,27,"" );
        	}
        	break;   
        case 3:
	       	if ( who->get_legend(TASK_43,7) && !who->get_legend(TASK_43,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������ʵ���������վã���Ȼ��֪��һЩ������ߵģ������¹��ش��Ҳ������׿��ڰ���\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
	       	else if ( who->get_legend(TASK_43,8) && !who->get_legend(TASK_43,9) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������������ѵķ��ϣ��һ��Ǹ�����ɣ���������û�а��ոɵ�ʼ��ٸ��֮ǰ����ǧ��ĪҪ����˵��ȥ������¹���һ�Ҵ�С�İ�Σ���������һ��ǿ�����ž�����һ���������Գ���һ�����٣�Ҫ��ֻ�����ٿ��»�����������������ѣ���Ϊ���µ������Ų�֪�����Ǹ���ʿ�����֪��Ҫ��������Ҫ�Ե����˵�����100�������½��������������ʮ����ʧ���ڴˣ����¾������������֣������ųƣ�ֻҪ���ǲ��ҷ��������������ǻ���������������Ǽ��˵�����ȥ�ԣ�����������ɥ�������Ķ�ħΪ�ڣ�����Ҳ����ʳ�Ѱ�����������˭������ȥ������ţ�����ĳԣ����»�����������Ż�³�����׳ʿ���������ⲻ��ɱ�����ţ�����������ȥ�ɣ�Ҫ��Ȼ��������һ����С�������ĺ��̰���\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
	       	else if ( who->get_legend(TASK_43,9) && !who->get_legend(TASK_43,10) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��˵��������а�Ĵ󷨣���Ȼ��֪���κβ������ţ��㻹��������ȥ�ɣ��㶷��������Īǣ�����ǡ�\n"ESC"�뿪", me->get_name()));
	       	else if ( who->get_legend(TASK_43,10) && !who->get_legend(TASK_43,11) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ģ������ħ�������ˣ�л��л�أ����ǿ���˯�����Ⱦ��ˡ�\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
	       	else if ( who->get_legend(TASK_43,11) && !who->get_legend(TASK_43,12) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������ӣ�Ϊ��������������ֻ��֪ͨ������׼�������ˡ������Ż֮����һ������Щʧ����Ա����������˵�����������������������в���һ���������ǰȥ����ȡ�ؽ������������١�\n"ESC"��������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));

        	break;		
        case 4:
	       	if ( who->get_legend(TASK_43,7) && !who->get_legend(TASK_43,8) )
		{
			if (TASK_LEGEND_D->check_task_item(who,"�ݷ���",1) != 1 )
        			return;
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_43,8);
			who->add_exp(96000);
			who->add_potential(1900);
			who->add_cash(92000);
			send_user(who,"%c%s",';',"���֪���� ���� 96000 Ǳ�� 1900 ��Ǯ 92000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,89,"" );
			me->do_welcome(3);
        	} 
		break;
	case 5:
		if ( who->get_legend(TASK_43,8) && !who->get_legend(TASK_43,9) )
		{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_43,9);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,90,"�����в" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�����в");
        	}
		break;
        case 6:
	       	if ( who->get_legend(TASK_43,10) && !who->get_legend(TASK_43,11) )
		{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_43,11);
			who->add_exp(99000);
			who->add_potential(1800);
			who->add_cash(91000);
			send_user(who,"%c%s",';',"�����в ���� 99000 Ǳ�� 1800 ��Ǯ 91000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,90,"" );
			me->do_welcome(3);
        	} 
		break;
	case 7:
		if ( who->get_legend(TASK_43,11) && !who->get_legend(TASK_43,12) )
		{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_43,12);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,91,"Ѱ������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"Ѱ������");
        	}
		break;
	case 21:
        case 22:
        	TASK_ESCORT_D->biaowang(me,who,flag);
        }
}