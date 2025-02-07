
#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <action.h>
#include <music.h>

string *PlantName = ({ "����", "һ��", "����", "����", "�ĳ�", "���", "����", "�߳�", "�˳�", "�ų�", "����" });

// �������Ի�����
void do_look_1( object me, object who )
{
        string cmd1, cmd2, cmd3, cmd4, cmd5;
        string result;
        int id = getoid(who);

        if(     !me->is_farmer()
        ||      me->get_task("plant") != sprintf( "%x#", id ) )
        {
                send_user( me, "%c%s", ':', "����һ�óɳ��е�ũ���" );
                return;
        }

        cmd1 = sprintf( "talk %x# plant.1\n", id );
        cmd2 = sprintf( "talk %x# plant.2\n", id );
        cmd3 = sprintf( "talk %x# plant.3\n", id );
        cmd4 = sprintf( "talk %x# plant.4\n", id );
        cmd5 = sprintf( "talk %x# plant.5\n", id );

        if( who->get("time") >= 10 ) 
                result = "�������˳����Ĺ�ʵ��";
        else switch( who->get("plant") )
        {
      default : result = "";  break;
       case 1 : result = "�������Ӳݴ�����";  break;
       case 2 : result = "��֦Ҷ�ݻƣ��ƺ��е�Ӫ��������";  break;
       case 3 : result = "�����������ɺԹ��ѡ�";  break;
       case 4 : result = "��֦Ҷ������һЩС���ӡ�";  break;
        }

        result = sprintf( "ũ����ĳɳ���Ϊ %d��%s\n", who->get("time"), result );
        send_user( me, "%c%s", ':', result +
                ESC "��Ҫ���ݡ�\n" + cmd1 +
                ESC "��Ҫʩ�ʡ�\n" + cmd2 +
                ESC "��Ҫ��ˮ��\n" + cmd3 +
                ESC "��Ҫ���档\n" + cmd4 +
                ESC "��Ҫ�ո\n" + cmd5 +
                ESC "ʲô��������\nCLOSE\n" );
}

// ��������������
void do_plant( object me, object who, string arg )
{
        object city, obj, obj2;
        int work, gold, exp, exp2, level, p;

        if( !me->is_farmer() )
        {
                send_user(me, "%c%s", '!', "������ũ�򣬲����ø��֡�");
                return;
        }
        if( me->get_task("plant") != sprintf( "%x#", getoid(who) ) )
        {
                send_user(me, "%c%s", '!', "�ⲻ������ũ���");
                return;
        }
        if( me->get_strength() < 1 )
        {
                send_user(me, "%c%s", '!', "�����ڵ�����������");
                return;
        }

        if( !arg || arg == "" ) return;
        if( !( work = to_int(arg) ) ) return;

        obj = me->get_equip(HAND_TYPE);
        level = me->get_occupation_level();

        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 02011, 10, OVER_BODY, PF_ONCE );

        if( work == 5 && who->get("time") >= 10 )    // �ո�
        {
                me->add_strength(-1);    // ũ���� +60, ��ʵ +3, ���� +60, �¸� +60, ���� +3, ���ҹ��� +10
                exp2 = 60;  me->add_occupation_exp(exp2);
                me->add_gift_zs(3);
                me->add_gift_cx(60);
                me->add_gift_yg(60);
                me->add_repute(3);
                me->add_contribute(10);
                gold = level * 2 + 20;  me->add_cash(gold);  me->add_gold_log("task", gold);
                me->log_money("ũ��", gold);
                "/sys/sys/count"->add_income("task", gold);
                exp = level * 10 + 100;  me->add_exp(exp);
                me->add_potential(10);

                write_user( me, ECHO "���ɹ����ո���ũ���" );

                who->remove_from_scene();
                destruct(who);

                send_user( me, "%c%w", 0x0d, MUSIC_TASK );
                write_user( me, ECHO "����ũ���� +60, ��ʵ +3, ���� +60, �¸� +60, ���� +3, ���ҹ��� +10, ��Ǯ %+d, ���� %+d, Ǳ�� +10��", gold, exp );

                if( !( city = CITY_D->get_city_object(me) ) ) return;

                work = level * 10 + 250;
                if( obj && obj->get_name() == "����" ) work = work * 120 / 100;
                city->add_food(work);

                p = random(100);

                if( p < 50 )    // �õ��¼�
                {
                        p = random(100);

                        if( p < 30 )    // ���з���
                        {
                                city->add_food(1000);
                                write_user( me, ECHO "%s���е����ݻ�÷��գ��������� 1000 �㡣", city->get_name() );
                        }
                        else if( p < 60 )
                        {
                                me->add_cash(1000);  me->add_gold_log("task", 1000);
                                me->log_money("ũ��", 1000);
                                "/sys/sys/count"->add_income("task", 1000);
                                write_user( me, ECHO "���ڳ���һЩֵǮ�Ķ��������õ� 1000 ��" );
                        }
                        else if( p < 80 )    // �ڳ�ҩ��
                        {
                                switch( random(35) )
                                {
                               case 0 : obj2 = new( "/item/90/9001" );  break;
                               case 1 : obj2 = new( "/item/90/9002" );  break;
                               case 2 : obj2 = new( "/item/90/9003" );  break;
                               case 3 : obj2 = new( "/item/90/9004" );  break;
                               case 4 : obj2 = new( "/item/90/9010" );  break;
                               case 5 : obj2 = new( "/item/90/9011" );  break;
                               case 6 : obj2 = new( "/item/90/9012" );  break;
                               case 7 : obj2 = new( "/item/90/9020" );  break;
                               case 8 : obj2 = new( "/item/90/9021" );  break;
                               case 9 : obj2 = new( "/item/90/9022" );  break;
                              case 10 : obj2 = new( "/item/90/9023" );  break;
                              case 11 : obj2 = new( "/item/90/9030" );  break;
                              case 12 : obj2 = new( "/item/90/9031" );  break;
                              case 13 : obj2 = new( "/item/90/9032" );  break;
                              case 14 : obj2 = new( "/item/90/9040" );  break;
                              case 15 : obj2 = new( "/item/90/9041" );  break;
                              case 16 : obj2 = new( "/item/90/9042" );  break;
                              case 17 : obj2 = new( "/item/90/9050" );  break;
                              case 18 : obj2 = new( "/item/90/9051" );  break;
                              case 19 : obj2 = new( "/item/90/9052" );  break;
                              case 20 : obj2 = new( "/item/90/9060" );  break;
                              case 21 : obj2 = new( "/item/90/9061" );  break;
                              case 22 : obj2 = new( "/item/90/9062" );  break;
                              case 23 : obj2 = new( "/item/90/9070" );  break;
                              case 24 : obj2 = new( "/item/90/9071" );  break;
                              case 25 : obj2 = new( "/item/90/9072" );  break;
                              case 26 : obj2 = new( "/item/90/9073" );  break;
                              case 27 : obj2 = new( "/item/90/9074" );  break;
                              case 28 : obj2 = new( "/item/90/9080" );  break;
                              case 29 : obj2 = new( "/item/90/9081" );  break;
                              case 30 : obj2 = new( "/item/90/9082" );  break;
                              case 31 : obj2 = new( "/item/90/9083" );  break;
                              case 32 : obj2 = new( "/item/90/9084" );  break;
                              case 33 : obj2 = new( "/item/90/9085" );  break;
                              case 34 : obj2 = new( "/item/90/9086" );  break;
                                }
                                write_user( me, ECHO "������ڳ���%s��", obj2->get_name() );
                                if( p = obj2->move(me, -1) ) obj2->add_to_user(p);
                                else destruct(obj2);
                        }
                        else if( p < 90 )    // �ڳ��ر�ͼ
                        {
                                obj2 = new( "/item/std/8000" );
                                if( p = obj2->move(me, -1) ) obj2->add_to_user(p);
                                else destruct(obj2);
                                write_user( me, ECHO "������ڳ���һ�Ųر�ͼ��" );
                        }
                        else if( p < 92 )    // �ڳ���ʯ
                        {
                        }
                        else 
                        {
                                me->add_strength(20);
                                write_user( me, ECHO "���Ƕ����Ĺ����޲����ڣ������������� 20 �㡣" );
                        }
                }
                else if( p < 60 )    // �����¼�(ְҵ����ӱ�)
                {
                        p = random(100);

                        if( p < 50 )
                        {
                                city->add_food( -1000 );
                                me->add_occupation_exp(exp2);
                                write_user( me, ECHO "%s���е����ݷ���Ǹ�գ����ݼ��� 1000 �㡣", city->get_name() );
                        }
                        else
                        {
                                me->add_strength( -20 );
                                me->add_occupation_exp(exp2);
                                write_user( me, ECHO "��ͻȻ�����ʮ�����ۣ������������� 20 �㡣" );
                        }
                }

                return;
        }

        if( who->get("plant") == work )
        {
                switch( work )
                {
               case 1 : if( obj && obj->get_name() == "���ݳ�" ) 
                                who->add("time", 2);
                        else    who->add("time", 1);
                        write_user( me, ECHO "����ũ������ݣ���������ø����ˡ�" );
                        who->set_head_code_2(0);
                        break;
               case 2 : who->add("time", 1);  
                        write_user( me, ECHO "����ũ����ʩ�ʣ���������ø����ˡ�" );
                        who->set_head_code_2(0);
                        break;
               case 3 : if( obj && obj->get_name() == "СľͰ" ) 
                                who->add("time", 2);
                        else    who->add("time", 1);
                        write_user( me, ECHO "����ũ���ｽˮ����������ø����ˡ�" );
                        who->set_head_code_2(0);
                        break;
               case 4 : who->add("time", 1);  
                        write_user( me, ECHO "����ũ������棬��������ø����ˡ�" );
                        who->set_head_code_2(0);
                        break;
                }
                if( who->get("time") > 10 ) who->set("time", 10);
                level = who->get("time");  if( level < 0 ) level = 0;
                who->set_name( sprintf( "%s(%s)", PlantName[level], me->get_name() ) );    // ��������
                who->delete("plant");
        }
        else if( work == 5 )
        {
                write_user( me, ECHO "�������ո���ũ������һ������" );
                who->remove_from_scene();
                destruct(who);
        }
        else
        {
                if( who->add("time", -1) < 0 )
                {
                        write_user( me, ECHO "��û�����Ϻ�ũ�������������ˡ�" );
                        who->remove_from_scene();
                        destruct(who);
                }
        }
}

// �������Ի�����
void do_look_2( object me, object who )
{
        object city;
        string cmd, result;

        if(     me->is_farmer()
        &&    ( city = CITY_D->get_city_object(who) ) )
        {
                cmd = sprintf( "talk %x# fish\n", getoid(who) );
                result = ( city->get_2("fish.total") > city->get_2("fish.kill") * 2 ) ? "" : "�Ѿ����̵���ʣ�޼��ˣ�";
                result = sprintf( "�����������Ϊ %d��%s���룺\n", who->get("fish"), result );
                send_user( me, "%c%s", ':', result +
                        ESC "��Ҫ���㡣\n" + cmd +
                        ESC "ʲô��������\nCLOSE\n" );
        }
}

// ���������㴦��
void do_fish( object me, object who, string arg )
{
        if( !me->is_farmer() )
        {
                send_user(me, "%c%s", '!', "������ũ�򣬲����ò��㡣");
                return;
        }
        if( gone_time( me->get_time("work") ) < 10 )
        {
                send_user(me, "%c%s", '!', "�����ڹ���֮���ء�");
                return;
        }
        if( me->get_strength() < 1 )
        {
                send_user(me, "%c%s", '!', "�����ڵ�����������");
                return;
        }

        write_user( me, ECHO "���ſ�����ʼ���㡭��" );

        me->set_time( "work", time() );
        call_out( "do_fish_finish", 10, me, who, arg );
}

// �������������
void do_fish_finish( object me, object who, string arg )
{
        object city, city2, obj;
        int p;
        int level, cx, yg, gold, exp, exp2, flag;

        if( !me || !who ) return;

        if( distance_between(who, me) > 3 )
        {
                send_user(me, "%c%s", '!', "����������ЩԶ�ˡ�");
                return;
        }

        if( !( city = CITY_D->get_city_object(who) ) ) return;
        if( !( city2 = CITY_D->get_city_object(me) ) ) return;

        level = me->get_occupation_level();

        if( random(100) < 60 + level / 5 )    // ����ɹ�
        {
                write_user( me, ECHO "���ɹ��ز�����һЩ�㣡" );
                who->add("fish", -1);
                city->add_2("fish.kill", 1);
                flag = 1;
        }
        else
        {
                write_user( me, ECHO "��һ��С�����������ˡ�" );
                flag = 0;
        }

        me->add_strength(-1);    // ���� -1, ũ���� +10, ��ʵ +1, ���� +10, �¸� +10, ���� +1, ���ҹ��� +1
        exp2 = 10;  me->add_occupation_exp(exp2);
        me->add_gift_zs(1);

        if( city->get_2("fish.total") > city->get_2("fish.kill") * 2 )
        {
                cx = 10;  me->add_gift_cx(cx);
                yg = 10;  me->add_gift_yg(yg);
                if( flag ) 
                {
                        gold = level * 2 + 20;  me->add_cash(gold);  me->add_gold_log("task", gold);
                        me->log_money("ũ��", gold);
                        city2->add_food(level * 2 + 20);
                }
        }
        else    // �������
        {
                cx = 5;  me->add_gift_cx(cx);    // �������ԡ���Ǯ����
                yg = 5;  me->add_gift_yg(yg);
                if( flag ) 
                {
                        gold = level + 10;  me->add_cash(gold);  me->add_gold_log("task", gold);
                        me->log_money("ũ��", gold);
                        "/sys/sys/count"->add_income("task", gold);
                        "/sys/sys/count"->add_income("task", gold);
                        city2->add_food(level + 10);
                }
        }

        me->add_repute(1);
        me->add_contribute(1);
        exp = level * 4 + 40;  me->add_exp(exp);
        me->add_potential(1);

        send_user( me, "%c%w", 0x0d, MUSIC_TASK );
        write_user( me, ECHO "����ũ���� %+d, ��ʵ +1, ���� %+d, �¸� %+d, ���� +1, ���ҹ��� +1, ��Ǯ %+d, ���� %+d, Ǳ�� +1��", 
                exp2, cx, yg, gold, exp );

        if( who->get("fish") < 1 )    // ��ȫ������
        {
                write_user( me, ECHO "��������Ѿ�ȫ�����������ˡ�" );
                who->remove_from_scene();
                destruct(who);
        }
}
