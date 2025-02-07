// inquisitor ��ʷ������

#include <ansi.h>

#define MAX_ELECTOR     50              // ��ѡ����

// �������Ի�����
void do_look( object who, object me )
{
        string name1, name2;
        string cmd1, cmd2, cmd3, cmd4;
        int id = getoid(me);

        name1 = who->get_city_name();
        name2 = me->get_city_name();
        
        send_user( who, "%c%s", '!', "��ѡ������δ���š�" );
        return;

        if( stringp(name1) && stringp(name2) && name1 == name2 )
        {
                cmd1 = sprintf( "talk %x# elect.?\n", id );
                cmd2 = sprintf( "talk %x# vote.?\n", id );
                cmd3 = sprintf( "talk %x# vote.@\n", id );
                cmd4 = sprintf( "talk %x# score\n", id );
                send_user( who, "%c%s", ':', me->get_name() + "��\n    "+"/quest/word"->get_country_word(me)+"\n    " + who->get_name() + "������ʲô���飿\n" 
                        ESC "�����μӾ�ѡ��(�� 1000 ��)\n" + cmd1 +
                        ESC "ͶƱѡ�ٳ�����\n" + cmd2 +
                        ESC "�鿴��ѡ���顣\n" + cmd3 +
                        ESC "���۱��ˡ�\n" + cmd4 +
                        ESC "�뿪��\nCLOSE\n" );
        }
        else
        {
                send_user( who, "%c%s", ':', me->get_name() + "��\n    "+ "/quest/word"->get_country_word(me));
        }
}

private static mapping elect;

// ������Ʊ���ȶ�
int vote_cmp( string key1, string key2 )
{
        return elect[key2] - elect[key1];
}

// ������Ʊ������
void sort_elector( object city, object me )
{
        string *key, *list;
        int *list_id, i, size;

        me->delete( "list" );
        me->delete( "list_id" );

        if(     city->get_save_2("elect.day")
        &&      mapp( elect = city->get_save_2( "elect.vote" ) )
        &&    ( size = sizeof(elect) ) )
        {
                list = ({ });  list_id = ({ });
                key = sort_array( keys(elect), (: vote_cmp($1, $2) :) );
                for( i = 0; i < size && i < MAX_POSITION - 1; i ++ )
                {
                        list += ({ sprintf( "%s(%s) - %d", city->get_save_2( "elect.name." + key[i] ), key[i], elect[ key[i] ] ) });
                        list_id += ({ to_int( key[i] ) });
                }
                city->set_save_2( "elect.first", key[0] );
                me->set( "list", list );
                me->set( "list_id", list_id );
        }
}

// ��������������
void do_elect( object who, object me, string arg )
{
        object city;
        string name1, name2;
        string cmd, id, result;

        name1 = who->get_city_name();
        name2 = me->get_city_name();
        
        send_user( who, "%c%s", '!', "��ѡ������δ���š�" );
        return;

        if(     stringp(name1) && stringp(name2) && name1 == name2
        &&    ( city = CITY_D->get_city_object(who) ) )
        {
                if( city->get_save_2("elect.day") < 1 )
                {
                        send_user(who, "%c%s", '!', "����û��ѡ�ٻ��");
                        return;
                }

                id = sprintf( "%d", who->get_number() );

                if( city->get_save_2( "elect.id." + id ) )
                {
                        send_user(who, "%c%s", '!', "���Ѿ��Ǻ�ѡ���ˡ�");
                        return;
                }
                if( sizeof( city->get_save_2( "elect.id" ) ) >= MAX_ELECTOR )
                {
                        send_user(who, "%c%s", '!', "�����Ѿ����㹻��ѡ�ˡ�");
                        return;
                }

                if( who->get_cash() < 1000 )
                {
                        send_user( who, "%c%s", '!', "�����ϵ��ֽ𲻹���" );
                        return;
                }

                if( arg == "?" )
                {
                        cmd = sprintf( "talk %x# elect\n", getoid(me) );
                        send_user( who, "%c%s", ':', "��ȷ���μӳ�����ѡ��\n" 
                                ESC "�ǵġ�\n" + cmd +
                                ESC "�������롭��\nCLOSE\n" );
                }
                else 
                {
                        who->add_cash( -1000 );  who->add_gold_log("pay", 1000);
                        who->log_money("��ѡ", -1000);
                        "/sys/sys/count"->add_use("pay", 1000);
                        city->set_save_2( "elect.id." + id, who->get_id() );
                        city->set_save_2( "elect.name." + id, who->get_name() );
                        city->set_save_2( "elect.vote." + id, 0 );
                        sort_elector(city, me);
                        city->save();

                        result = sprintf( HIY "%s(%d)���㾺ѡ����������ӻԾ��ѡ��ͶƱ��", who->get_name(), who->get_number(), name1 );
                        FAMILY_D->city_channel(name1, 0, result);
                }
        }
}

// ������ͶƱ����
void do_vote( object who, object me, string arg )
{
        object city;
        string name1, name2;
        string cmd, *list, result;
        int *list_id, id, total, i, size;

        name1 = who->get_city_name();
        name2 = me->get_city_name();

        if(     stringp(name1) && stringp(name2) && name1 == name2
        &&    ( city = CITY_D->get_city_object(who) ) )
        {
                if( city->get_save_2("elect.day") < 1 )
                {
                        send_user(who, "%c%s", '!', "����û��ѡ�ٻ��");
                        return;
                }

                elect = city->get_save_2( "elect.vote" );

                if( !( size = sizeof(elect) ) )
                {
                        send_user(who, "%c%s", '!', "���ڻ�û�к�ѡ�ˡ�");
                        return;
                }

                if( arg == "@" )
                {
                        if( !arrayp( list = me->get( "list" ) ) )
                        {
                                sort_elector(city, me);
                                list = me->get( "list" );
                        }

                        result = sprintf( "���¾�ѡ���飺\n" );
                        for( i = 0, size = sizeof(list); i < size; i ++ )
                        {
                                result += sprintf( ESC "%s\nCLOSE\n", list[i] );
                        }
                        result += sprintf( ESC "�رմ��ڡ�\nCLOSE\n" );
                        send_user( who, "%c%s", ':', result);
                        return;
                }

                if( who->get_save("vote") == city->get_save_2("elect.day") )
                {
                        send_user(who, "%c%s", '!', "���Ѿ�Ͷ��Ʊ�ˡ�");
                        return;
                }

                total = who->get_level();

                if( arg == "?" )
                {
                        if( !arrayp( list = me->get( "list" ) ) )
                        {
                                sort_elector(city, me);
                                list = me->get( "list" );
                        }
                        list_id = me->get("list_id");  id = getoid(me);

                        result = sprintf( "���� %d Ʊ�������ѡƱͶ��˭��\n", total );
                        for( i = 0, size = sizeof(list); i < size; i ++ )
                        {
                                result += sprintf( ESC "%s\ntalk %x# vote.?.%d\n", list[i], id, list_id[i] );
                        }
                        result += sprintf( ESC "ͶƱ�������ˡ�\ntalk %x# vote.?.?\n", id );
                        send_user( who, "%c%s", ':', result);
                }
                else if( arg == "?.?" )
                {
                        send_user( who, "%c%c%d%s", '?', 1, 0, sprintf( "���� %d Ʊ�������ѡƱͶ��˭��������Է������֣ɣģ�"
                                ESC "talk %x# vote.?.%%s\n", total, getoid(me) ) );
                }
                else if( sscanf(arg, "?.%d", id) )
                {
                        arg = sprintf("%d", id);
                        if( !city->get_save_2("elect.id." + arg) )
                        {
                                send_user(who, "%c%s", '!', "�����û�вμӾ�ѡ��");
                                return;
                        }

                        result = sprintf( "��ȷ����ƱͶ��%s(%d)��\n", city->get_save_2( sprintf( "elect.name.%d", id ) ), id );
                        cmd = sprintf( "talk %x# vote.%d\n", getoid(me), id );
                        send_user( who, "%c%s", ':', result +
                                ESC "�ǵġ�\n" + cmd +
                                ESC "�������롭��\nCLOSE\n" );
                }
                else if( sscanf(arg, "%d", id) )
                {
                        arg = sprintf("%d", id);
                        if( !city->get_save_2("elect.id." + arg) )
                        {
                                send_user(who, "%c%s", '!', "�����û�вμӾ�ѡ��");
                                return;
                        }

                        who->set_save( "vote", city->get_save_2("elect.day") );
                        city->add_save_2( "elect.vote." + arg, total );
                        sort_elector(city, me);

                        write_user( who, ECHO "���� %d ѡƱͶ��%s(%s)����Ʊ���ﵽ %d��\n", 
                                total, city->get_save_2("elect.name." + arg), arg, city->get_save_2("elect.vote." + arg) );
                }
        }
}
