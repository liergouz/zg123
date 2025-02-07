// general ����

#include <ansi.h>
#include <city.h>
#include <cmd.h>
#include <skill.h>

// �������Ի�����
void do_look( object who, object me )
{
        string name1, name2;
        string cmd1, cmd2, cmd3, cmd4, cmd5;

        name1 = who->get_city_name();
        name2 = me->get_city_name();
 
        if( stringp(name1) && stringp(name2) && name1 == name2 )
        {
                if( who->is_soldier() )
                {
                        cmd1 = sprintf( "talk %x# patrol\n", getoid(me) );
                        cmd2 = sprintf( "talk %x# soldier\n", getoid(me) );
                        cmd3 = sprintf( "talk %x# armor\n", getoid(me) );
                        cmd4 = sprintf( "talk %x# taofa\n", getoid(me) );
                        cmd5 = sprintf( "talk %x# baowei\n", getoid(me) );
                        send_user( who, "%c%s", ':', me->get_name() + "��\n    " + "/quest/word"->get_country_word(me) + "\n    " + who->get_name() + "�����������к����飿\n" 
                                ESC "�μӳ���Ѳ�ߡ�\n" + cmd1 +
                                ESC "��ȡ��������\n" + cmd2 +
                                ESC "��ȡս������\n" + cmd3 +
                                ESC "�ַ��й���\n" + cmd4 +
                                ESC "������԰��\n" + cmd5 +
                                ESC "�뿪��\nCLOSE\n" );
                }
                else
                {
                        send_user( who, "%c%s", ':', me->get_name() + "��\n    "+"/quest/word"->get_country_word(me) );
                }
        }
        else
        {
                send_user( who, "%c%s", ':', me->get_name() + "��\n    "+ "/quest/word"->get_country_word(me) );
        }
}

// ����������Ѳ��
void do_patrol( object who, object me, string arg )
{
        object city;
        string name1, name2;

        name1 = who->get_city_name();
        name2 = me->get_city_name();

        if(     stringp(name1) && stringp(name2) && name1 == name2
        &&      who->is_soldier()
        &&    ( city = CITY_D->get_city_object(who) ) )
        {
                if( who->get_2("train.patrol") )
                {
                        send_user( who, "%c%s", ':', me->get_name() + "��\n������Ѳ��һ�£�����˭����С���š�\n" );
                        return;
                }
                if( who->get_strength() < 1 )
                {
                        send_user(who, "%c%s", '!', "�����ڵ�����������");
                        return;
                }

                who->set_2("train.patrol", 1);
                send_user( who, "%c%s", ':', me->get_name() + "��\n������Щ��С���ڵ��ң����Ĵ�Ѳ�ߴ���һ�°ɡ�\n" );
        }
}

// ��������������
void do_soldier( object who, object me, string arg )
{
        object city;
        string name1, name2;

        name1 = who->get_city_name();
        name2 = me->get_city_name();

        if(     stringp(name1) && stringp(name2) && name1 == name2
        &&      who->is_soldier()
        &&    ( city = CITY_D->get_city_object(who) ) )
        {
                if( city->is_soldier_enough() )
                {
                        send_user( who, "%c%s", ':', me->get_name() + "��\n����ʿ���Ѿ��㹻�ˣ�����Ҫ�������ˡ�\n" );
                        return;
                }
                if( who->get_2("train.soldier") )
                {
                        send_user( who, "%c%s", ':', me->get_name() + "��\n���ڳ��и�����Աһ�£�����˭Ը��ξ��ɡ�\n" );
                        return;
                }
                if( who->get_strength() < 1 )
                {
                        send_user(who, "%c%s", '!', "�����ڵ�����������");
                        return;
                }

                who->set_2("train.soldier", 1);
                send_user( who, "%c%s", ':', me->get_name() + "��\n���ڳ��и�����Աһ�£�����˭Ը��ξ��ɡ�\n" );
        }
}

// ������ս������
void do_armor( object who, object me, string arg )
{
        object city;
        string name1, name2;

        name1 = who->get_city_name();
        name2 = me->get_city_name();

        if(     stringp(name1) && stringp(name2) && name1 == name2
        &&      who->is_soldier()
        &&    ( city = CITY_D->get_city_object(who) ) )
        {
                if( city->get_armor() >= city->get_soldier() )
                {
                        send_user( who, "%c%s", ':', me->get_name() + "��\n����װ���Ѿ��㹻�ˣ�����Ҫ�������ˡ�\n" );
                        return;
                }
                if( who->get_2("train.armor") )
                {
                        send_user( who, "%c%s", ':', me->get_name() + "��\n��ȥ��������һ�£�����������װ����\n" );
                        return;
                }
                if( who->get_strength() < 1 )
                {
                        send_user(who, "%c%s", '!', "�����ڵ�����������");
                        return;
                }

                who->set_2("train.armor", 1);
                send_user( who, "%c%s", ':', me->get_name() + "��\n��ȥ��������һ�£�����������װ����\n" );
        }
}
