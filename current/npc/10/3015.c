
// �Զ����ɣ�/make/npc/make-collect

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <music.h>

inherit OFFICER;

void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 5505; }

// ���������촦��
void create()
{
        set_name("��ʦ");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      
	set("mpLegend2",([0:({32*26+23,}),]));
        setup();
}

// �������Ի�����
// �������Ի�����
void do_look( object who )
{
	string tmp="";
	object me = this_object();
	
        tmp += CHAIN_D->get_chain_menu(who,me);
        if ( who->get_legend(TASK_26,22) && !who->get_legend(TASK_26,23) ) 
		tmp += sprintf(ESC HIY "���յĺ���\ntalk %x# welcome.1\n",getoid(me)); 
        if ( who->get_legend(TASK_26,23) && !who->get_legend(TASK_26,24) ) 
		tmp += sprintf(ESC HIY "��ʦ������\ntalk %x# welcome.1\n",getoid(me)); 
    
        send_user( who, "%c%s", ':', sprintf( "%s��\n    %s\n", get_name(),TASK_COLLECT_D->get_talk_string(0421))
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
	       	if ( who->get_legend(TASK_26,22) && !who->get_legend(TASK_26,23) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ء������ܸ�л��Ҷ���ô������ѽ�����ǣ���������ʲô����ѽ���Ҹ�����ԩ���İ���\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
	       	else if ( who->get_legend(TASK_26,23) && !who->get_legend(TASK_26,24) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ҵĸ��ױ����Ǵ����������������Ѿ��ڹ����̷��˴���ʮ�����ˡ����ǣ������Ϊ���������һ�����ﺬ���鱻�ԣ�����֮�¾�Ȼ˵���Ҹ���͵�ġ������������������У��Ͱ��Ҹ��׶����ռ��ˡ������Ҹ��������Һ��Ǿ��Բ���͵�����ģ���һ��ҪΪ�Ҹ������ߣ�����԰��ҽ�����߿��齻��������ʷ֣����\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        		
        	break;
	case 2:
        	if ( who->get_legend(TASK_26,22) && !who->get_legend(TASK_26,23) )
        	{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_26,23);
			who->add_exp(41000);
			who->add_potential(600);
			who->add_cash(41000);
			send_user(who,"%c%s",';',"���յĺ��� ���� 41000 Ǳ�� 600 ��Ǯ 41000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,36,"" );
			me->do_welcome(1);
        	}
        	break;     
	case 3:
        	if( who->get_legend(TASK_26,23) && !who->get_legend(TASK_26,24) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		item = new("item/98/0124");
        		if ( !item )
        			return ;
        		p = item->move(who,-1);
        		if ( !p )
        		{
        			destruct(item);
        			send_user(who,"%c%s",'!', "��Я������Ʒ̫����");
        			return;
        		}
        		item->add_to_user(p);
        		who->set_legend(TASK_26,24);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_HANGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,37,"��ʦ������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ʦ������");
        	}
        	break;
 
        }
}  