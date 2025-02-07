
#include <ansi.h>
#include <map.h>
#include <npc.h>
#include <effect.h>

inherit TALISMAN;

// ��������Ч����
int get_active_rate() { return 50; }

// ����������ʶ��
int get_talisman_type() { return 5; }

// ���������촦��
void create()
{
        set_name( "������" );
        set_picid_1(9541);
        set_picid_2(9541);
        set_unit( "��" );

        set_level(1);
        set_value(5000);
        set_max_lasting(4099);

        setup();
}

// ��������ȡ����
string get_desc() 
{ 
        return "����������ҵ���ǰ���������λ��";
}

// ��������ʹ�÷���
int is_usable_2() { return 1; }

// ������ʹ�÷���Ч��
int get_use_effect_2( object me, object who, string arg ) { return __DIR__ "9541" ->get_use_effect_2_callout( me, who, this_object(), arg ); }

// ������ʹ�÷���Ч��(���߸���)
int get_use_effect_2_callout( object me, object who, object item, string arg )    // ͬ�����ġ����з���
{
        object map, npc;
        int z, x, y, p;

        if( !objectp(who) ) return 1;

        if( !who->is_user() ) return 1;    // ���������

        if( who->get_login_flag() < 3 ) return 1;    // û��׼������

        if( who->is_die() || who->is_store_open() || who->get_no_fight() ) return 1;    // ��������̯����ȫ��

        if( me == who ) return 1;    // �������Լ�
        if ( time() - me->get_save("9541")<600)
        {
                send_user( me, "%c%s", '!', sprintf("������%d�����ʹ�������", 600+me->get_save("9541")-time()) );
                return 1;        	
        }

        if( objectp( map = get_map_object( get_z(who) ) ) && map->get_map_type() == BATTLE_MAP )
        {
                send_user( me, "%c%s", '!', "�Է����ڻ���ս����" );
                return 1;
        }
	if( who->get_save_2("51cuanye.time") )
	{
		send_user(me, "%c%s", '!', "�Է����ܼ��޴�Խ�������ʹ�������");
		return 0;
	}        
        if( present("ǮƱ", who, 1, MAX_CARRY) )
        {
                send_user( me, "%c%s", '!', "�Է����ϴ���ǮƱ��" );
                return 1;
        }
        if( present("������Ʒ", who, 1, MAX_CARRY*4) )
        {
                send_user( me, "%c%s", '!', "�Է����ϴ��Ź�����Ʒ��" );
                return 1;
        }       
        if( objectp( npc = who->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // Ѱ��������
        {
                send_user( me, "%c%s", '!', "�Է������������ˡ�" );
                return 1;
        }

        item->add_lasting(-1);    // ʹ�ü����;�

        me->set_char_type( PK_TYPE );    // �����У�״̬
        set_effect(me, EFFECT_USER_PK, 120);
        me->set_save("9541", time());

        if(     random(100) < item->get_active_rate()    // �ɹ���
        &&    ( z = get_z(who) )
        &&    ( p = get_xy_point(z, IS_CHAR_BLOCK) ) )
        {
                x = p / 1000;  y = p % 1000;

//              if( MAP_D->is_inside_city(z, x, y) ) return 1;

/*              who->set_login_flag(2);    // ��ת����
                set_invisible(who, 1);
                set_effect(who, EFFECT_USER_LOGIN, 4);   */

                if(   ( npc = who->get_quest("escort.npc") )    // ��������
                &&      npc->get_owner() == who
                &&      inside_screen_2(who, npc) )    // ͬ��Ļ��
                        npc->add_to_scene( z, x, y, get_d(who), 40991, 40992, 40991, 40992 );

                if( p = get_valid_xy( z, x + random(3) - 1, y + random(3) - 1, IS_CHAR_BLOCK ) )
                {
                        who->add_to_scene( z, p / 1000, p % 1000, get_d(who), 40991, 40992, 40991, 40992 );
                }

                write_user( me, ECHO "��ʹ��" HIY "�������" ECHO "��%s�����ˡ�", who->get_name() );
                write_user( who, ECHO "%sʹ��" HIY "�������" ECHO "���������ˡ�", me->get_name() );

                return 1;
        }
        else    write_user( me, ECHO "����%sʹ��" HIY "�������" ECHO "ʧ���ˡ�", who->get_name() );	
        return 1;
}
