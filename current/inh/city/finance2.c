// minister of finance ������

#include <ansi.h>
#include <action.h>
#include <music.h>

#define INTERIOR_D      "/inh/city/interior"

// ��������������(����)
void do_comput( object who, object me, string arg )
{
        string name1, name2;
        int level, exp;
        int x, y, z, id;

        id = getoid(me);

        name1 = who->get_city_name();
        name2 = me->get_city_name();

        if(     stringp(name1) && stringp(name2) && name1 == name2
        &&      who->get_save_2("build.flag") == 2
        &&      gone_time( who->get_save_2("build.time") ) < 2400 )
        {
                if( who->get_save_2("build.comput") == to_int(arg) )    // ����ȷ���� 0 ����
                {
                        if( who->add_save_2("build.count", 1) > 20 )    // �������
                        {
                                level = who->get_level();

                                who->add_contribute(1);    // ���ҹ��� +1
                                exp = level * random(50) + 1000;  who->add_exp(exp);
                                who->add_potential(5);

                                send_user( who, "%c%w", 0x0d, MUSIC_TASK );
                                write_user( who, ECHO "���Ĺ��ҹ��� +1, ���� %+d, Ǳ�� +5��", exp );

                                who->delete_save_2("build");    // ɾ�������־

                                INTERIOR_D->do_build_finish(who, me);    // �� me �Է� BUG��Ҫ set_city_name

                                return;
                        }
                }

                x = random(100) + 1;
	        y = random(100) + 1;
	        z = who->get_save_2("build.count");

	        switch( random(2) )
	        {
	      default : who->set_save_2("build.comput", x + y);
                        send_user( who, "%c%c%d%s", '?', 1, 1000, sprintf( "%s��\n�� %d �⣬%d ���� %d ���ڶ��٣�\n"
                                ESC "talk %x# comput.%%s\n", me->get_name(), z, x, y, id ) );
	                break;
	       case 1 : if( x > y ) 
	                {
	                        who->set_save_2("build.comput", x - y);
                                send_user( who, "%c%c%d%s", '?', 1, 1000, sprintf( "%s��\n�� %d �⣬%d ��ȥ %d ���ڶ��٣�\n"
                                        ESC "talk %x# comput.%%s\n", me->get_name(), z, x, y, id ) );
	                }
	                else 
	                {
	                        who->set_save_2("build.comput", y - x);
                                send_user( who, "%c%c%d%s", '?', 1, 1000, sprintf( "%s��\n�� %d �⣬%d ��ȥ %d ���ڶ��٣�\n"
                                        ESC "talk %x# comput.%%s\n", me->get_name(), z, y, x, id ) );
	                }
	                break;
                }
        }
}
