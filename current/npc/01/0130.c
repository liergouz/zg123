
#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <music.h>

inherit OFFICER;

void do_fight();

// ��������ȡ��������
int get_char_picid() { return 5901; }

// ���������촦��
void create()
{
        set_name( "���Ϻ�" );

        set_2( "talk", ([
                "fight"         : (: do_fight :),
        ]));

        setup();
}

// �������Ի�����
void do_look( object who )
{
        string cmd,tmp="";
        int level, gold, exp;
/*
        if( who->get_level() == 26 )
        {
                if( !who->get_legend(TASK_NEWBIE_02, 1) )
                {
                        cmd = sprintf( "talk %x# fight\n", getoid( this_object() ) );
                        send_user( who, "%c%s", ':', get_name() + "��\n�����ҽ�ѵ�˼�ֻɽ�������Ұ��Ҳ��������͵�����ԣ�������������ǻ����������ܰ��ҳ���������\n" 
                                ESC "û���⡣\n" + cmd +
                                ESC "�뿪��\nCLOSE\n" );
                        return;
                }
                else if( !who->get_legend(TASK_NEWBIE_02, 2)
                ||      !who->get_legend(TASK_NEWBIE_02, 3)
                ||      !who->get_legend(TASK_NEWBIE_02, 4)
                ||      !who->get_legend(TASK_NEWBIE_02, 5)
                ||      !who->get_legend(TASK_NEWBIE_02, 6)
                ||      !who->get_legend(TASK_NEWBIE_02, 7)
                ||      !who->get_legend(TASK_NEWBIE_02, 8)
                ||      !who->get_legend(TASK_NEWBIE_02, 9)
                ||      !who->get_legend(TASK_NEWBIE_02, 10)
                ||      !who->get_legend(TASK_NEWBIE_02, 11)
                ||      !who->get_legend(TASK_NEWBIE_02, 12)
                ||      !who->get_legend(TASK_NEWBIE_02, 13)
                ||      !who->get_legend(TASK_NEWBIE_02, 14)
                ||      !who->get_legend(TASK_NEWBIE_02, 15)
                ||      !who->get_legend(TASK_NEWBIE_02, 16) )
                {
                        send_user( who, "%c%s", ':', get_name() + "��\n����ѵ��Ұ������\n" );
                        return;
                }
                else if( !who->get_legend(TASK_NEWBIE_02, 17) )
                {
                        send_user( who, "%c%s", ':', who->get_name() + "��\n�ҽ�ѵ��Ұ������\n\n" +
                                get_name() + "��\nлл���ˣ�����Ϊ������Ĵ�Ӣ�۰���\n" );

                        who->set_legend(TASK_NEWBIE_02, 17);
                        level = who->get_level();
                        gold = level * 500;  who->add_cash(gold);  who->add_gold_log("task", gold);
                        exp = level * level * level * 4;  who->add_exp(exp);

                        send_user( who, "%c%w", 0x0d, MUSIC_TASK );
                        write_user( who, ECHO "������������񣬽�Ǯ %+d, ���� %+d��", gold, exp );

                        return;
                }
        }
*/        
        tmp += CHAIN_D->get_chain_menu(who,this_object());
        send_user( who, "%c%s", ':', get_name() + "��\n�Դӽ�ѵ��Ұ�ú����Ǿͺ��ٵ�������͵����������\n"
        +tmp +
        ESC"�뿪" );
}

// �������Ի�����
void do_fight()
{
        object me, who;

        me = this_object();  who = this_player();
/*
        if( who->get_level() == 26 )
        {
                if( !who->get_legend(TASK_NEWBIE_02, 1) )
                {
                        send_user( who, "%c%s", ':', get_name() + "��\n������Ұ�⣬���æȥ��ѵ��ѵҰ�ðɡ�\n" );
                        who->set_legend(TASK_NEWBIE_02, 1);
                        USER_TASK_D->auto_give_task(who);
                        return;
                }
        }
*/        
}
