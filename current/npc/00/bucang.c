
#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <music.h>
#define CUR_BUCANG 	2

inherit OFFICER;

void do_look( object who );
void do_welcome( string arg );


// ��������ȡ��������
int get_char_picid() { return 6009; }

// ���������촦��
void create()
{
        set_name( "����ʹ��" );

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	int x;
	string cmd1, result;
	object me= this_object();
	cmd1 = sprintf("talk %x# welcome.1\n", getoid(me));
	result =  get_name() + "��\n    ��Ϊ��ιٷ����޸����Թ��û���ɵĲ��㣬�����ر�Ϊ���ṩ��һ�β������ᡣ��ס�������Ļ���ֻ��һ�Σ���������еĲ�������ȡ���֮���Ҳ����ٸ������κεĲ�����һ��Ҫ�úð���Ӧ�á�������ȡ������\n"
		ESC "��ȡ\n" + cmd1 +
		ESC "ȡ��\nCLOSE\n";
	send_user( who, "%c%c%w%s", ':', 3, 6009, result );
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	string result;
	object who;
	int level, exp, flag, pot, money; 
	who = this_player();
	flag = to_int(arg);
        switch(flag)
        {
        case 1:
        	if (who->get_save("buchang")>=CUR_BUCANG)
        	{
	                result =  get_name() + "��\n    �������Ѿ������������\n"
	                		ESC "�뿪\nCLOSE\n";
			send_user( who, "%c%c%w%s", ':', 3, 6009, result );
			return ;
        	}
        	if (who->get_birthday()>1156417200)
        	{
	                result =  get_name() + "��\n    ��β���ֻ���2006��8��24��19:00֮ǰע������\n"
	                		ESC "�뿪\nCLOSE\n";
			send_user( who, "%c%c%w%s", ':', 3, 6009, result );
			return ;
        	}
        	who->set_save("buchang", CUR_BUCANG);
        	level = who->get_level();
        	exp = level*5000*3;
        	pot = level*200*3;
        	money = level*2000*3;
        	who->add_exp(exp);
        	who->add_potential(pot);
        	who->add_cash(money);
	        result =  get_name() + sprintf("��\n    �������˾���%d��Ǳ��%d����Ǯ%d��\n"
	        		ESC "�뿪\nCLOSE\n", exp, pot, money);
			        	
		send_user( who, "%c%c%w%s", ':', 3, 6009, result );        	
                break;
        }
}

