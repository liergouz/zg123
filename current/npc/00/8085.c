
#include <npc.h>
#include <ansi.h>

inherit OFFICER;

void do_goto();
void do_recover();

// ��������ȡ��������
int get_char_picid() { return 5109; }

// ���������촦��
void create()
{
        set_name("��ʦ");
	set_real_name("����");

        set_2( "talk", ([
                "go"    : (: do_goto :),
                "recover"    : (: do_recover :),
        ]));

        setup();
}

// �������Ի�����
void do_look( object who )
{
        more_look_menu( who, get_name() + "��\n��λ" + NPC_RANK_D->get_respect(who) + "��ȥ���䳡�����д��д���\n"
                ESC "ȥ���䳡��\n" + sprintf( "talk %x# go\n", getoid( this_object() ) ) +
                ESC "����һָ���\n" + sprintf( "talk %x# recover\n", getoid( this_object() ) ) +
                ESC "�뿪��\nCLOSE\n" );
}

// �������ƶ�����
void do_goto()
{
        object who;
        int p, z, x, y;

        who = this_player();

        if( p = get_jumpin(885, 1) )
        {
        	x = 80;  y = 60; z = 885;
        	if( p = get_valid_xy( z, x + random(40) - 20, y + random(40) - 20, IS_CHAR_BLOCK ) )
        	{
	                write_user( who, get_name() + "˵�������ڱ��䳡�д��ǲ��������ģ��������԰ɣ���" );
		                
	                who->add_to_scene( z, p / 1000, p % 1000, get_d(who) );
		}	               
        }
}

// ��������Ѫ����
void do_recover()
{
        object who;
        int hp, mp, yuan, cash;
	string result;
        who = this_player();
	hp = who->get_max_hp() - who->get_hp();
	mp = who->get_max_mp() - who->get_mp();
	yuan = who->get_max_yuan() - who->get_yuan();
	cash = hp * 2 + mp * 2 + yuan * 2000;
	if (cash==0)
	{
		result =  "�㲻��Ҫ���ƣ�";
		send_user( who, "%c%s", '!', result ); 		
		return ;	
	}
	if (who->get_cash()<cash)
	{		
	        result =  get_name() + "��\n    �����ϵ�Ǯ���񲻶࣬������û�취����ָ��ġ�������������ͷ���Ļ�������ȥ��ξ������ͷ��������ͷ��æ��\n"
	        		ESC "�ر�\nCLOSE\n";
	        send_user( who, "%c%c%w%s", ':', 3, 5109, result ); 		
	       	return ;
	}
	who->add_cash(-cash);
	who->set_hp(who->get_max_hp());
	who->set_mp(who->get_max_mp());
	who->set_yuan(who->get_max_yuan());
	result =  sprintf("��õ������ƣ�������%d�Ľ�Ǯ��", cash);
	send_user( who, "%c%s", '!', result ); 		
}