
#include <npc.h>
#include <ansi.h>
#include <equip.h>

inherit NPC;

// ����������ǿ��
int is_escort_robber() { return 1; }

// ����������ǿ��(quest)
int is_escort_robber_2() { return 1; }

// �������Ƿ��ܽ���
int cannot_enter_city() { return 1; }

// ���������촦��
void create()
{
        set_name("��ؤ");
        set_char_picid(451);    // ������
        set_char_type(FIGHTER_TYPE);

        setup();

        set( "birthday", time() );
}

// ��������ȡװ������
int get_weapon_code() { return UNARMED; }

// ��������ȡ��ǰ�ȣ�
int get_hp() { return get_max_hp(); }    // �޷�ɱ��

// ���������õ�ǰ�ȣ�
int set_hp( int point ) { return get_max_hp(); }

// ����������ǰ�ȣ�
int add_hp( int point ) { return get_max_hp(); }

// ��������ȡ��Ѫ����
int get_hp_cent() { return 50; }

// ��������λ����
void reset()
{
        object owner, item;

        if( gone_time( get("birthday") ) >= 600 )    // 10 ����
        {
                if(     objectp( owner = find_player( sprintf("%d", get("task") ) ) )
                &&      objectp( item = present("������Ʒ", owner, 1, MAX_CARRY) ) )
                        item->set_heart_3min();    // �¸�������

                remove_from_scene();
                destruct( this_object() );
        }
}

// ���������Խ���ս��
/*      int can_be_fighted( object who ) 
{ 
        object owner;
        int id;

        if( who->get_enemy() == this_object() ) return 1;

        if( owner = who->get_owner() ) who = owner;
        if( who->is_npc() ) return 0;

        id = who->get_number();
        if( get("task") == id || get("task2") == id ) return 1;

        send_user( who, "%c%s", '!', get_name() + "����ͬ���ܡ�" );
        return 0;
}       */

// --------------------------------------------------------------- Զ�̵��� ----

// ���������ܽ�Ǯ
int accept_money( object who, int gold ) { return __FILE__ ->accept_money_callout( this_object(), who, gold ); }

// ���������ܽ�Ǯ(���߸���)
int accept_money_callout( object me, object who, int gold )
{
        object item;
        string file;
        int z, x, y, p;

        if( who->is_user() && me->get("task") == who->get_number() )
        {
                if( !me->get("gold") ) me->set("gold", random(30) + 1);

                if( me->get("gold") == gold )    // ������ȷ
                {
                        if( random(1000) < 5 && load_object( file = BOOK_FILE->get_book_file() ) )    // 1% // �����ؼ�
                        {
                                item = new( file );
                                if( p = item->move(who, -1) ) 
                                {
                                        item->add_to_user(p);
                                        write_user(who, ECHO "%s���� %s��", me->get_name(), item->get_name() );
                                       	send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s��\n    ��λ%s�����������棬��������ĺò��ϣ��Ȿ��������ؤ����Ҳû�ã���������ˡ�",me->get_name(),NPC_RANK_D->get_respect_2(who)));
                                }
                                else    destruct(item);
                        }
                }
                else    // ��������
                {
                        if(   ( z = get_z(who) )
                        &&    ( p = get_xy_point(z, IS_CHAR_BLOCK) ) )
                        {
                                who->add_to_scene( z, p / 1000, p % 1000, get_d(who) );
                                write_user(who, ECHO "%s�����ˣ��������˳�ȥ��", me->get_name() );
                        }
                }

                call_out( "destruct_npc_callout", 3, me, who );    // ���������

                return 1;
        }
        return 0;
}

// ������ɾ���Լ�(���߸���)
void destruct_npc_callout( object me, object who )
{
	if (!me) return;
        me->win_bonus(who);    // ���������
        me->remove_from_scene();
        destruct(me);
}

// ���������Խ���ս��
int can_be_fighted( object who ) { return __FILE__ ->can_be_fighted_callout( this_object(), who ); }

// ���������Խ���ս��(���߸���)
int can_be_fighted_callout( object me, object who ) 
{
	int i; 
        if( who->is_user() && me->get("task") == who->get_number() )
        {
                if( !me->get("gold") ) me->set("gold", random(30) + 1);
                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s��\n    �š������������λ�����ˣ����������Ұɣ���%d������в��С���Ȼ�Ҿ������ô򣬲������ߡ�\n"ESC"ʩ��%d���\ngive %x# 0#0 0#0 0#0 0#0 0#0 0#0 $%d\n"ESC"�뿪", me->get_name(), i=me->get("gold"),i,getoid(me),i ) );
        }
        return 0;
}

// ��������������(����֮�е���)
void heart_beat_attack() { }    // ��ֹս��

// ��������������
void win_bonus( object who ) { __FILE__ ->win_bonus_callout( this_object(), who ); }

// ��������������(���߸���)
void win_bonus_callout( object me, object who )    // �����������
{
        object owner, item;

        if(     objectp( owner = find_player( sprintf("%d", me->get("task") ) ) )
        &&      objectp( item = present("������Ʒ", owner, 1, MAX_CARRY) ) )
                item->set_heart_3min();    // �¸�������
}
