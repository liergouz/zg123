// emperor �������ʵ�

#include <ansi.h>
#include <music.h>

void do_advice( object who, object me, string arg );

// �������Ի�����
void do_look( object who, object me )
{
        object city, city2;
        string name1, name2, name3, result;
        string cmd1, cmd2, cmd3;
        int id, flag, city0, city7;

        id = getoid(me);

        name1 = who->get_city_name();
        name2 = me->get_city_name();
        if ( "/sys/task/master"->do_look2(who, me)==1 )
        	return ;  
        if(   ( city7 = who->get_save_2("relation.city2") )
        &&      CITY_D->get_city_name(city7) == name2
        &&      gone_time( who->get_save_2("relation.time") ) < 2400    // 40 ����
        &&    ( flag = who->get_save_2("relation.flag") )
        &&    ( city = CITY_D->get_city_object(me) )
        &&    ( city0 = who->get_save_2("relation.city") )
        &&    ( city2 = CITY_D->get_city_object_2(city0) ) )
        {
                name3 = CITY_D->get_city_name( who->get_save_2("relation.city") );

                if( random(100) < 30 + who->get_level() / 2 )
                {
                        switch( flag )
                        {
                      default : send_user( who, "%c%s", ':', sprintf( "����\n����%sʹ�ڣ�Я������������������ꡣ\n\n\n"
                                        "%s��\n���Ҿ������ˣ�Ը���������Ѻú�����\n", name3, me->get_name() ) );

                                city->add_friend(city0, 20);
                                city2->add_friend(city7, 20);
                                city->add_money(100000);
                                city2->add_money(-100000);

                                result = sprintf( "%s��%s���� 100000 ���������������ꡣ", name3, name2 );
                                FAMILY_D->city_channel(name2, 0, result);
                                FAMILY_D->city_channel(name3, 0, result);

                                break;

                       case 2 : send_user( who, "%c%s", ':', sprintf( "����\n����%sʹ�ڣ����Ƚ��ղ������ҹ����෬ɧ�ţ��������ء�\n\n\n"
                                        "%s��\n����̫�������Ϳͣ�\n", name3, me->get_name() ) );

                                city->add_friend(city0, -20);
                                city2->add_friend(city7, -20);

                                result = sprintf( "%s��ʹ����%s���˫���Ѻö��½���", name3, name2 );
                                FAMILY_D->city_channel(name2, 0, result);
                                FAMILY_D->city_channel(name3, 0, result);

                                break;
                        }

                        flag = who->get_level() * 70 + 1000;
                        who->add_exp(flag);
                        who->add_potential(5);

                        send_user( who, "%c%w", 0x0d, MUSIC_TASK );
                        write_user( who, ECHO "���ľ��� %+d, Ǳ�� +5��", flag );
                }
                else
                {
                        switch( flag )
                        {
                      default : send_user( who, "%c%s", ':', sprintf( "����\n����%sʹ�ڣ�Я������������������ꡣ\n\n\n"
                                        "%s��\n����������ϵ��û��������У�������ذɡ�\n", name3, me->get_name() ) );
                                break;
                       case 2 : send_user( who, "%c%s", ':', sprintf( "����\n����%sʹ�ڣ����Ƚ��ղ������ҹ����෬ɧ�ţ��������ء�\n\n\n"
                                        "%s��\n��������ˣ��������������Ѻã��������⡣\n", name3, me->get_name() ) );
                                break;
                        }

                        who->add_exp(1);
                        who->add_potential(1);

                        write_user( who, ECHO "���ľ��� +1, Ǳ�� +1��" );
                }

                who->delete_save_2("relation");

                return;
        }
        if( who->is_scholar() )
        {
                if( who->get_save_2("advice.city") || who->get_save_2("advice.city2") )
                {
                        do_advice(who, me, "");    // ����ݺ�����
                        return;
                }
        }

        if( stringp(name1) && stringp(name2) && name1 == name2 && who->get_id() == me->get_master() )
        {
                cmd1 = sprintf( "talk %x# policy.?\n", id );
                cmd2 = sprintf( "talk %x# relation.?\n", id );
                cmd3 = sprintf( "talk %x# master.?\n", id );
                send_user( who, "%c%s", ':', me->get_name() + "��\n    "+"/quest/word"->get_country_word(me)+"\n    " + who->get_name() + "���䣬��������ʲô������\n" 
                        ESC "�������\n" + cmd1 +
                        ESC "�ƶ��⽻���ԡ�\n" + cmd2 +
                        ESC "�����������顣\n" + cmd3 +
                        ESC "���¡�\nCLOSE\n" );
        }
        else if( who->is_scholar() )
        {

                cmd1 = sprintf( "talk %x# advice.1\n", id );
                cmd2 = sprintf( "talk %x# advice.2\n", id );

                send_user( who, "%c%s", ':', me->get_name() + "��\n    "+"/quest/word"->get_country_word(me) + "\n    "+ who->get_name() + "������ʲô���飿\n" 
                        ESC "ͬ����޺á�\n" + cmd1 +
                        ESC "�������\n" + cmd2 +
                        ESC "���¡�\nCLOSE\n" );
        }
        else
        {
                send_user( who, "%c%s", ':', me->get_name() + "��\n    "+"/quest/word"->get_country_word(me) );
        }
}

// �����������
void do_policy( object who, object me, string arg )
{
        object city;
        string name1, name2, name3, result;
        string cmd1, cmd2;
        int number, id;

        id = getoid(me);

        name1 = who->get_city_name();
        name2 = me->get_city_name();

        if(     stringp(name1) && stringp(name2) && name1 == name2 
        &&      who->get_id() == me->get_master()
        &&    ( city = CITY_D->get_city_object(who) ) )
        {
                if( who->get_strength() < 50 )
                {
                        send_user(who, "%c%s", '!', "��������Ҫ 50 ��������");
                        return;
                }

                if( !arg || arg == "?" )
                {
                        cmd1 = sprintf( "talk %x# policy.?.1\n", id );
                        cmd2 = sprintf( "talk %x# policy.?.2\n", id );
                        send_user( who, "%c%s", ':', "���뽨��" + me->get_name() + "����ʲô���(���� 50 ����)\n"
                                ESC "�����\n" + cmd1 +
                                ESC "����\n" + cmd2 +
                                ESC "�������롭��\nCLOSE\n" );
                }
                else if( sscanf( arg, "?.%d", number ) )
                {
                        switch( number )
                        {
                      default : name3 = "������";  break;
                       case 2 : name3 = "�����";  break;
                        }

                        cmd1 = sprintf( "talk %x# policy.%d\n", id, number );
                        send_user( who, "%c%s", ':', sprintf( "��ȷ������%s����%s��\n", me->get_name(), name3 ) + 
                                ESC "�ǵġ�\n" + cmd1 +
                                ESC "�������롭��\nCLOSE\n" );
                }
                else if( number = to_int(arg) )
                {
                        switch( number )
                        {
                      default : city->set_save_2("policy.flag", 1);
                                city->set_save_2("policy.time", time() );
                                who->add_strength(-50);

                                result = sprintf( HIY "%s�������������������������ʿ������", me->get_name() );
                                FAMILY_D->city_channel(name2, 0, result);

                                break;

                       case 2 : city->set_save_2("policy.flag", -1);
                                city->set_save_2("policy.time", time() );
                                who->add_strength(-50);

                                result = sprintf( HIY "%s����������л��������ɫ֮ͽ������", me->get_name() );
                                FAMILY_D->city_channel(name2, 0, result);

                                break;
                        }
                }
        }
}

// ���������ִ���
void do_master( object who, object me, string arg )
{
        object city, master;
        string name1, name2;
        string cmd1, cmd2, player;
        string result;
        int id = getoid(me);

        name1 = who->get_city_name();
        name2 = me->get_city_name();

        if(     stringp(name1) && stringp(name2) && name1 == name2 
        &&      who->get_id() == me->get_master()
        &&    ( city = CITY_D->get_city_object(who) ) )
        {
                if( arg == "?" )
                {
                        cmd1 = sprintf( "talk %x# master.+\n", id );
                        cmd2 = sprintf( "talk %x# master.-\n", id );
                        send_user( who, "%c%s", ':', "��ͬ" + me->get_name() + "̸���ڸ����������顣\n"
                                ESC "�ټ���������\n" + cmd1 +
                                ESC "������������\n" + cmd2 +
                                ESC "�������롭��\nCLOSE\n" );
                }
                else if( arg == "+" )
                {
                        if( city->get_master_2() != "" && city->get_master_3() != "" )
                        {
                                send_user(who, "%c%s", '!', "������ְȱ�����λ��");
                                return;
                        }
                        send_user( who, "%c%c%d%s", '?', 1, 0, sprintf( "������%s�ټ�˭����������������Է������֣ɣģ�\n"
                                ESC "talk %x# master.+.?.%%s\n", me->get_name(), id ) );
                }
                else if( arg == "-" )
                {
                        if( city->get_master_2() == "" && city->get_master_3() == "" )
                        {
                                send_user(who, "%c%s", '!', "���ڻ�û�и�������");
                                return;
                        }
                        result = sprintf( "������%s������λ��������\n", me->get_name() );
                        if( city->get_master_2() != "" )
                        {
                                result += sprintf( ESC "%s\ntalk %x# master.-.?.1\n",
                                        city->get_master_name_2(), id );
                        }
                        if( city->get_master_3() != "" )
                        {
                                result += sprintf( ESC "%s\ntalk %x# master.-.?.2\n",
                                        city->get_master_name_3(), id );
                        }
                        send_user( who, "%c%s", ':', result +
                                ESC "�������롭��\nCLOSE\n" );
                }
                else if( sscanf( arg, "+.?.%s", player ) )
                {
                        if( city->get_master_2() != "" && city->get_master_3() != "" )
                        {
                                send_user(who, "%c%s", '!', "������ְȱ�����λ��");
                                return;
                        }
                        if( !( master = find_player(player) ) )
                        {
                                send_user(who, "%c%s", '!', "�޷��ҵ���λ��ҡ�");
                                return;
                        }
                        else if( master == who )
                        {
                                send_user(who, "%c%s", '!', "�����ܾټ����Լ���");
                                return;
                        }
                        else if( master->get_city_name() != name1 )
                        {
                                send_user(who, "%c%s", '!', "���ټ����˷Ǳ�����ʿ��");
                                return;
                        }
                        else if( city->get_master_2() == master->get_id() || city->get_master_3() == master->get_id() )
                        {
                                send_user(who, "%c%s", '!', "���ټ������Ѿ��Ǹ������ˡ�");
                                return;
                        }

                        result = sprintf( "��ȷ����%s�ټ�%s(%d)����������\n", 
                                me->get_name(), master->get_name(), master->get_number() );
                        cmd1 = sprintf( "talk %x# master.+.%s\n", id, player );
                        send_user( who, "%c%s", ':', result +
                                ESC "�ǵġ�\n" + cmd1 +
                                ESC "�������롭��\nCLOSE\n" );
                }
                else if( sscanf( arg, "+.%s", player ) )
                {
                        if( city->get_master_2() != "" && city->get_master_3() != "" )
                        {
                                send_user(who, "%c%s", '!', "������ְȱ�����λ��");
                                return;
                        }
                        if( !( master = find_player(player) ) )
                        {
                                send_user(who, "%c%s", '!', "�޷��ҵ���λ��ҡ�");
                                return;
                        }
                        else if( master == who )
                        {
                                send_user(who, "%c%s", '!', "�����ܾټ����Լ���");
                                return;
                        }
                        else if( master->get_city_name() != name1 )
                        {
                                send_user(who, "%c%s", '!', "���ټ����˷Ǳ�����ʿ��");
                                return;
                        }
                        else if( city->get_master_2() == master->get_id() || city->get_master_3() == master->get_id() )
                        {
                                send_user(who, "%c%s", '!', "���ټ������Ѿ��Ǹ������ˡ�");
                                return;
                        }

                        if( city->get_master_2() == "" )
                        {
                                city->set_master_2( master->get_id() );
                                city->set_master_name_2( sprintf( "%s(%s)", master->get_name(), player ) );
                        }
                        else if( city->get_master_3() == "" )
                        {
                                city->set_master_3( master->get_id() );
                                city->set_master_name_3( sprintf( "%s(%s)", master->get_name(), player ) );
                        }
                        city->save();

                        result = sprintf( HIY "%s���ܳ���%s�ټ���ί��%s(%d)���θ�������", 
                                me->get_name(), who->get_name(), master->get_name(), master->get_number() );
                        FAMILY_D->city_channel(name1, 0, result);
                }
                else if( arg == "-.?.1" )
                {
                        if( city->get_master_2() == "" )
                        {
                                send_user(who, "%c%s", '!', "���޷�������λ��������");
                                return;
                        }
                        result = sprintf( "��ȷ����%s����%s��\n", me->get_name(), city->get_master_name_2() );
                        cmd1 = sprintf( "talk %x# master.-.1\n", id );
                        send_user( who, "%c%s", ':', result +
                                ESC "�ǵġ�\n" + cmd1 +
                                ESC "�������롭��\nCLOSE\n" );
                }
                else if( arg == "-.?.2" )
                {
                        if( city->get_master_3() == "" )
                        {
                                send_user(who, "%c%s", '!', "���޷�������λ��������");
                                return;
                        }
                        result = sprintf( "��ȷ����%s����%s��\n", me->get_name(), city->get_master_name_3() );
                        cmd1 = sprintf( "talk %x# master.-.2\n", id );
                        send_user( who, "%c%s", ':', result +
                                ESC "�ǵġ�\n" + cmd1 +
                                ESC "�������롭��\nCLOSE\n" );
                }
                else if( arg == "-.1" )
                {
                        if( city->get_master_2() == "" )
                        {
                                send_user(who, "%c%s", '!', "���޷�������λ��������");
                                return;
                        }

                        result = sprintf( HIY "%s���ܳ���%s��������ȥ%s������ְ��", 
                                me->get_name(), who->get_name(), city->get_master_name_2() );
                        FAMILY_D->city_channel(name1, 0, result);

                        city->set_master_2("");
                        city->set_master_name_2("����");
                        city->save();
                }
                else if( arg == "-.2" )
                {
                        if( city->get_master_3() == "" )
                        {
                                send_user(who, "%c%s", '!', "���޷�������λ��������");
                                return;
                        }

                        result = sprintf( HIY "%s���ܳ���%s��������ȥ%s������ְ��", 
                                me->get_name(), who->get_name(), city->get_master_name_3() );
                        FAMILY_D->city_channel(name1, 0, result);

                        city->set_master_3("");
                        city->set_master_name_3("����");
                        city->save();
                }
        }
}

// ���������鴦��
void do_advice( object who, object me, string arg )
{
        object city, city2;
        string name1, name2, name3, name4, result;
        string cmd1, cmd2, cmd3, cmd4, cmd5, cmd6;
        int number, id, city7;
        int level, rate, cash, exp;

        id = getoid(me);

        name1 = who->get_city_name();
        name2 = me->get_city_name();

        if( who->is_scholar() && ( city = CITY_D->get_city_object(me) ) )
        {
                if( who->get_occupation_level() < 80 )
                {
                        send_user(who, "%c%s", '!', "���������ȼ�������");
                        return;
                }
                if( ( level = gone_time( who->get_save_2("advice.time") ) ) < 300 )    // ����Ӻ�
                {
                        send_user(who, "%c%s", '!', sprintf("%d ���������Ὠ�顣", 300 - level) );
                        return;
                }

                if( !arg || arg == "" )    // ##################################################
                {
                        if( who->get_save_2("advice.city2") != CITY_D->get_city_number(name2) )
                        {
                                send_user(who, "%c%s", '!', "�����ݺ�����û����أ�");
                                return;
                        }
                        
                        number = who->get_save_2("advice.type");
                        city7 = who->get_save_2("advice.city");
                        if( city7 < 1 || city7 > 7 ) return;
                        if( city7 == who->get_save_2("advice.city2") ) return;

                        name4 = CITY_D->get_city_name(city7);
                        level = who->get_occupation_level();

                        switch( number )
                        {
                      default : // �޺�
                                switch( city->get_save_2("policy.flag") )
                                {
                              default : rate = level / 2 + 1;  break;
                               case 1 : rate = (level / 2 + 1) * 2;  break;
                              case -1 : rate = (level / 2 + 1) / 2;  break;
                                }

                                if( random(100) < rate )
                                {
                                        send_user( who, "%c%s", ':', sprintf( "����\n�Ҵ���%sǰ����������Я�֣���ͼ���Դ�ҵ��\n\n\n"
                                                "%s��\n������֮���ã������������̫���ˡ�\n", name4, me->get_name() ) );

                                        who->add_occupation_exp(40);    // �������� +40, ��ı + 40
                                        who->add_gift_zm(40);
                                        cash = 0;  exp = 0;

                                        if( city2 = CITY_D->get_city_object_2(city7) ) 
                                        {
                                                cash = level * 50 + 500;
                                                if( city2->get_tax() < cash ) cash = city2->get_tax();
                                                if( cash < 0 ) cash = 0;
                                                who->add_cash(cash);  who->add_gold_log("task", cash);
                                                who->log_money("�⽻", cash);
						"/sys/sys/count"->add_income("task", cash);
                                                exp = level * 50 + 500;
                                                who->add_exp(exp);
                                                
                                                city2->add_tax(-cash);
                                                number = level / 10 + 1;
                                                city->add_friend( city7, number );
                                                city2->add_friend( CITY_D->get_city_number(name2), number );
                                        }

                                        send_user( who, "%c%w", 0x0d, MUSIC_TASK );
                                        write_user( who, ECHO "������������ +40, ��ı +40, ��Ǯ %+d, ���� %+d��", cash, exp );
                                }
                                else 
                                {
                                        send_user( who, "%c%s", ':', sprintf( "����\n�Ҵ���%sǰ����������Я�֣���ͼ���Դ�ҵ��\n\n\n"
                                                "%s��\n����û�н��˵���˼����ĺ����������ˡ�\n", name4, me->get_name() ) );

                                        who->add_occupation_exp(1);

                                        write_user( who, ECHO "������������ +1��" );
                                }

                                who->delete_save_2("advice");

                                break;

                       case 2 : // ����
                                switch( city->get_save_2("policy.flag") )
                                {
                              default : rate = level / 2 + 1;  break;
                               case 1 : rate = (level / 2 + 1) * 2;  break;
                              case -1 : rate = (level / 2 + 1) / 2;  break;
                                }

                                if( random(100) < rate )
                                {
                                        send_user( who, "%c%s", ':', sprintf( "����\n����%sʹ�ڣ����ȶ��ҹ�����ɧ���ƻ����Ǻε���\n\n\n"
                                                "%s��\n%s��Ը�������ң��Ե���ʩС�ͣ����ȥת��%s����������Ͷ������������\n", 
                                                name4, me->get_name(), name4, name4 ) );

                                        who->add_occupation_exp(40);    // �������� +40, ��ı + 40
                                        who->add_gift_zm(40);
                                        cash = 0;  exp = 0;

                                        if( city2 = CITY_D->get_city_object_2(city7) ) 
                                        {
                                                cash = level * 50 + 500;
                                                if( city2->get_tax() < cash ) cash = city2->get_tax();
                                                if( cash < 0 ) cash = 0;
                                                who->add_cash(cash);  who->add_gold_log("task", cash);
						"/sys/sys/count"->add_income("task", cash);
						who->log_money("�⽻", cash);
                                                exp = level * 50 + 500;
                                                who->add_exp(exp);

                                                city2->add_tax(-cash);
                                                number = level / 10 + 1;
                                                city->add_friend( city7, -number );
                                                city2->add_friend( CITY_D->get_city_number(name2), -number );
                                        }

                                        send_user( who, "%c%w", 0x0d, MUSIC_TASK );
                                        write_user( who, ECHO "������������ +40, ��ı +40, ��Ǯ %+d, ���� %+d��", cash, exp );
                                }
                                else 
                                {
                                        send_user( who, "%c%s", ':', sprintf( "����\n����%sʹ�ڣ����ȶ��ҹ�����ɧ���ƻ����Ǻε���\n\n\n"
                                                "%s��\n�����ļһ�����������ȡ�֣��콫���ϳ�ȥ��\n", name4, me->get_name() ) );

                                        who->add_occupation_exp(1);

                                        write_user( who, ECHO "������������ +1��" );
                                }

                                who->delete_save_2("advice");

                                break;
                        }

                        return;
                }

                if( who->get_save_2("advice.city") || who->get_save_2("advice.city2") )
                {
                        send_user(who, "%c%s", '!', "�����ݺ�����û����أ�");
                        return;
                }

                if( me->get( sprintf("advice_%d", time() / 86400) ) >= 200 )
                {
                        send_user(who, "%c%s", '!', me->get_city_name() + "�����������̫���ˡ�");
                        return;
                }
                if( who->get_strength() < 1 )
                {
                        send_user(who, "%c%s", '!', "�����ڵ�����������");
                        return;
                }

                if( sscanf( arg, "?.%d.%d", number, city7 ) == 2 )    // ##################################################
                {
                        if( city7 < 1 || city7 > 7 ) return;

                        name4 = CITY_D->get_city_name(city7);

                        switch( number )
                        {
                      default : name3 = "�޺�";  break;
                       case 2 : name3 = "����";  break;
                        }

                        cmd1 = sprintf( "talk %x# advice.%d.%d\n", id, number, city7 );
                        send_user( who, "%c%s", ':', sprintf( "��ȷ������%s��%s���С�%s����\n", me->get_name(), name4, name3 ) + 
                                ESC "�ǵġ�\n" + cmd1 +
                                ESC "�������롭��\nCLOSE\n" );
                }
                else if( sscanf( arg, "%d.%d", number, city7 ) == 2 )    // ##################################################
                {
                        if( city7 < 1 || city7 > 7 ) return;
                        if( city7 == CITY_D->get_city_number(name2) ) return;

                        name4 = CITY_D->get_city_name(city7);
                        level = who->get_occupation_level();

                        switch( number )
                        {
                      default : // �޺�
                                switch( city->get_save_2("policy.flag") )
                                {
                              default : rate = level / 3 + 20;  break;
                               case 1 : rate = (level / 3 + 20) * 2;  break;
                              case -1 : rate = (level / 3 + 20) / 2;  break;
                                }

                                if( random(100) < rate )
                                {
                                        send_user( who, "%c%s", ':', sprintf( "����\n%sǰ���Ǻ��л���ֻ�к�%s���˷�Ϊ�ϲߡ�\n\n\n"
                                                "%s��\n������֮������������Ϊ����ʹ�ڣ�ǰȥ%s���̽��˴�ơ�\n", 
                                                name2, name4, me->get_name(), name4 ) );

                                        who->add_strength(-1);    // ���� -1, �������� +20, ��ı + 20
                                        who->add_occupation_exp(20);
                                        who->add_gift_zm(20);
                                        who->add_exp(level * 10 + 200);

                                        who->set_save_2( "advice.city", CITY_D->get_city_number(name2) );
                                        who->set_save_2( "advice.city2", city7 );
                                        who->set_save_2( "advice.type", number );

                                        send_user( who, "%c%w", 0x0d, MUSIC_TASK );
                                        write_user( who, ECHO "������������ +20, ��ı +20, ���� %+d��", level * 10 + 200 );
                                }
                                else 
                                {
                                        send_user( who, "%c%s", ':', sprintf( "����\n%sǰ���Ǻ��л���ֻ�к�%s���˷�Ϊ�ϲߡ�\n\n\n"
                                                "%s��\n�ҹ�����ǿʢ��������ǿ��û��Ҫη���������ң��ݵ�Σ��������\n", 
                                                name2, name4, me->get_name() ) );

                                        who->add_strength(-1);    // ���� -1, �������� +1
                                        who->add_occupation_exp(1);

                                        who->set_save_2( "advice.time", time() );

                                        write_user( who, ECHO "������������ +1��" );
                                }

                                me->add( sprintf("advice_%d", time() / 86400), 1);

                                break;

                       case 2 : // ����
                                switch( city->get_save_2("policy.flag") )
                                {
                              default : rate = level / 3 + 20;  break;
                               case 1 : rate = (level / 3 + 20) * 2;  break;
                              case -1 : rate = (level / 3 + 20) / 2;  break;
                                }

                                if( random(100) < rate )
                                {
                                        send_user( who, "%c%s", ':', sprintf( "����\n%s����ı��%s�������Ѿ�������������ƻ��ˡ�\n\n\n"
                                                "%s��\n��Ȼ������£�������ȥ����%s��������������Ϊ��\n", 
                                                name4, name2, me->get_name(), name4 ) );

                                        who->add_strength(-1);    // ���� -1, �������� +20, ��ı + 20
                                        who->add_occupation_exp(20);
                                        who->add_gift_zm(20);
                                        who->add_exp(level * 10 + 200);

                                        who->set_save_2( "advice.city", CITY_D->get_city_number(name2) );
                                        who->set_save_2( "advice.city2", city7 );
                                        who->set_save_2( "advice.type", number );

                                        send_user( who, "%c%w", 0x0d, MUSIC_TASK );
                                        write_user( who, ECHO "������������ +20, ��ı +20, ���� %+d��", level * 10 + 200 );
                                }
                                else 
                                {
                                        send_user( who, "%c%s", ':', sprintf( "����\n%s����ı��%s�������Ѿ�������������ƻ��ˡ�\n\n\n"
                                                "%s��\n����������ҿ�û���յ�������Ϣ��\n", 
                                                name4, name2, me->get_name() ) );

                                        who->add_strength(-1);    // ���� -1, �������� +1
                                        who->add_occupation_exp(1);

                                        who->set_save_2( "advice.time", time() );

                                        write_user( who, ECHO "������������ +1��" );
                                }

                                me->add( sprintf("advice_%d", time() / 86400), 1);

                                break;
                        }
                }
                else if( number = to_int(arg) )    // ##################################################
                {
                        switch( number )
                        {
                      default : name3 = "�޺�";  break;
                       case 2 : name3 = "����";  break;
                        }

                        switch( name2 )
                        {
                      default : cmd1 = sprintf( "talk %x# advice.?.%d.2\n", id, number );
                                cmd2 = sprintf( "talk %x# advice.?.%d.3\n", id, number );
                                cmd3 = sprintf( "talk %x# advice.?.%d.4\n", id, number );
                                cmd4 = sprintf( "talk %x# advice.?.%d.5\n", id, number );
                                cmd5 = sprintf( "talk %x# advice.?.%d.6\n", id, number );
                                cmd6 = sprintf( "talk %x# advice.?.%d.7\n", id, number );
                                send_user( who, "%c%s", ':', sprintf( "���뽨��%s���Ĺ����С�%s����\n", me->get_name(), name3 ) + 
                                        ESC "������\n" + cmd1 +
                                        ESC "�Թ���\n" + cmd2 +
                                        ESC "κ����\n" + cmd3 +
                                        ESC "�ع���\n" + cmd4 +
                                        ESC "������\n" + cmd5 +
                                        ESC "�����\n" + cmd6 +
                                        ESC "�������롭��\nCLOSE\n" );
                                break;
                  case "����" : cmd1 = sprintf( "talk %x# advice.?.%d.1\n", id, number );
                                cmd2 = sprintf( "talk %x# advice.?.%d.3\n", id, number );
                                cmd3 = sprintf( "talk %x# advice.?.%d.4\n", id, number );
                                cmd4 = sprintf( "talk %x# advice.?.%d.5\n", id, number );
                                cmd5 = sprintf( "talk %x# advice.?.%d.6\n", id, number );
                                cmd6 = sprintf( "talk %x# advice.?.%d.7\n", id, number );
                                send_user( who, "%c%s", ':', sprintf( "���뽨��%s���Ĺ����С�%s����\n", me->get_name(), name3 ) + 
                                        ESC "�����\n" + cmd1 +
                                        ESC "�Թ���\n" + cmd2 +
                                        ESC "κ����\n" + cmd3 +
                                        ESC "�ع���\n" + cmd4 +
                                        ESC "������\n" + cmd5 +
                                        ESC "�����\n" + cmd6 +
                                        ESC "�������롭��\nCLOSE\n" );
                                break;
                  case "�Թ�" : cmd1 = sprintf( "talk %x# advice.?.%d.1\n", id, number );
                                cmd2 = sprintf( "talk %x# advice.?.%d.2\n", id, number );
                                cmd3 = sprintf( "talk %x# advice.?.%d.4\n", id, number );
                                cmd4 = sprintf( "talk %x# advice.?.%d.5\n", id, number );
                                cmd5 = sprintf( "talk %x# advice.?.%d.6\n", id, number );
                                cmd6 = sprintf( "talk %x# advice.?.%d.7\n", id, number );
                                send_user( who, "%c%s", ':', sprintf( "���뽨��%s���Ĺ����С�%s����\n", me->get_name(), name3 ) + 
                                        ESC "�����\n" + cmd1 +
                                        ESC "������\n" + cmd2 +
                                        ESC "κ����\n" + cmd3 +
                                        ESC "�ع���\n" + cmd4 +
                                        ESC "������\n" + cmd5 +
                                        ESC "�����\n" + cmd6 +
                                        ESC "�������롭��\nCLOSE\n" );
                                break;
                  case "κ��" : cmd1 = sprintf( "talk %x# advice.?.%d.1\n", id, number );
                                cmd2 = sprintf( "talk %x# advice.?.%d.2\n", id, number );
                                cmd3 = sprintf( "talk %x# advice.?.%d.3\n", id, number );
                                cmd4 = sprintf( "talk %x# advice.?.%d.5\n", id, number );
                                cmd5 = sprintf( "talk %x# advice.?.%d.6\n", id, number );
                                cmd6 = sprintf( "talk %x# advice.?.%d.7\n", id, number );
                                send_user( who, "%c%s", ':', sprintf( "���뽨��%s���Ĺ����С�%s����\n", me->get_name(), name3 ) + 
                                        ESC "�����\n" + cmd1 +
                                        ESC "������\n" + cmd2 +
                                        ESC "�Թ���\n" + cmd3 +
                                        ESC "�ع���\n" + cmd4 +
                                        ESC "������\n" + cmd5 +
                                        ESC "�����\n" + cmd6 +
                                        ESC "�������롭��\nCLOSE\n" );
                                break;
                  case "�ع�" : cmd1 = sprintf( "talk %x# advice.?.%d.1\n", id, number );
                                cmd2 = sprintf( "talk %x# advice.?.%d.2\n", id, number );
                                cmd3 = sprintf( "talk %x# advice.?.%d.3\n", id, number );
                                cmd4 = sprintf( "talk %x# advice.?.%d.4\n", id, number );
                                cmd5 = sprintf( "talk %x# advice.?.%d.6\n", id, number );
                                cmd6 = sprintf( "talk %x# advice.?.%d.7\n", id, number );
                                send_user( who, "%c%s", ':', sprintf( "���뽨��%s���Ĺ����С�%s����\n", me->get_name(), name3 ) + 
                                        ESC "�����\n" + cmd1 +
                                        ESC "������\n" + cmd2 +
                                        ESC "�Թ���\n" + cmd3 +
                                        ESC "κ����\n" + cmd4 +
                                        ESC "������\n" + cmd5 +
                                        ESC "�����\n" + cmd6 +
                                        ESC "�������롭��\nCLOSE\n" );
                                break;
                  case "����" : cmd1 = sprintf( "talk %x# advice.?.%d.1\n", id, number );
                                cmd2 = sprintf( "talk %x# advice.?.%d.2\n", id, number );
                                cmd3 = sprintf( "talk %x# advice.?.%d.3\n", id, number );
                                cmd4 = sprintf( "talk %x# advice.?.%d.4\n", id, number );
                                cmd5 = sprintf( "talk %x# advice.?.%d.5\n", id, number );
                                cmd6 = sprintf( "talk %x# advice.?.%d.7\n", id, number );
                                send_user( who, "%c%s", ':', sprintf( "���뽨��%s���Ĺ����С�%s����\n", me->get_name(), name3 ) + 
                                        ESC "�����\n" + cmd1 +
                                        ESC "������\n" + cmd2 +
                                        ESC "�Թ���\n" + cmd3 +
                                        ESC "κ����\n" + cmd4 +
                                        ESC "�ع���\n" + cmd5 +
                                        ESC "�����\n" + cmd6 +
                                        ESC "�������롭��\nCLOSE\n" );
                                break;
                  case "���" : cmd1 = sprintf( "talk %x# advice.?.%d.1\n", id, number );
                                cmd2 = sprintf( "talk %x# advice.?.%d.2\n", id, number );
                                cmd3 = sprintf( "talk %x# advice.?.%d.3\n", id, number );
                                cmd4 = sprintf( "talk %x# advice.?.%d.4\n", id, number );
                                cmd5 = sprintf( "talk %x# advice.?.%d.5\n", id, number );
                                cmd6 = sprintf( "talk %x# advice.?.%d.6\n", id, number );
                                send_user( who, "%c%s", ':', sprintf( "���뽨��%s���Ĺ����С�%s����\n", me->get_name(), name3 ) + 
                                        ESC "�����\n" + cmd1 +
                                        ESC "������\n" + cmd2 +
                                        ESC "�Թ���\n" + cmd3 +
                                        ESC "κ����\n" + cmd4 +
                                        ESC "�ع���\n" + cmd5 +
                                        ESC "������\n" + cmd6 +
                                        ESC "�������롭��\nCLOSE\n" );
                                break;
                        }
                }
        }
}
