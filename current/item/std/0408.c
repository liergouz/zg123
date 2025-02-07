
#include <ansi.h>
#include <map.h>
#include <effect.h>

inherit ITEM;
inherit COMBINED;
inherit USABLE;

// ���������촦��
void create()
{
        set_name( "���ŷ�" );
        set_picid_1(0408);
        set_picid_2(0408);
        set_unit( "��" );
        set_value(1500);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "���ͻ��������ڵ�";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me )
{
        object map, npc;
        int z, x, y, p;

        if( me->get_fam_name() == "" ) return 0;    // û������

        write_user(me, ECHO "������һ�Ż��ŷ�����");

        if( objectp( map = get_map_object( get_z(me) ) ) 
        	&& map->get_map_type() == BATTLE_MAP && !map->is_changping() )
        {
                send_user(me, "%c%s", '!', "��ս������ʹ�û��ŷ���");
//              write_user(me, ECHO "��������û���κ�Ч����");
                return 0;
        }
        if( present("ǮƱ", me, 1, MAX_CARRY) )
        {
                send_user(me, "%c%s", '!', "����ǮƱ����ʹ�û��ŷ���");
//              write_user(me, ECHO "��������û���κ�Ч����");
                return 0;
        }
        if( present("������Ʒ", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "���Ź�����Ʒ����ʹ�û��ŷ���");
//              write_user(me, ECHO "��������û���κ�Ч����");
                return 0;
        }
        if( objectp( npc = me->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // Ѱ��������
        {
                send_user(me, "%c%s", '!', "�����˳��֣������ж��ܵ�Ӱ�졣");
//              write_user(me, ECHO "��������û���κ�Ч����");
                return 0;
        }

        switch( me->get_fam_name() )
        {
              default : 
        case "�һ�Դ" : z = 289;  p = get_jumpin(z, 20);  break;
          case "��ɽ" : z = 273;  p = get_jumpin(z, 20);  break;
        case "������" : z = 080;  p = get_jumpin(z, 20);  break;
          case "����" : z = 324;  p = get_jumpin(z, 20);  break;
          case "éɽ" : z = 269;  p = get_jumpin(z, 20);  break;
        case "����ɽ" : z = 054;  p = get_jumpin(z, 20);  break;
        case "������" : z = 165;  p = get_jumpin(z, 20);  break;
        }

        if( p )
        {
                x = p / 1000;  y = p % 1000;
	        send_user(me, "%c%c%w%s", 0x5a, 0, 3, "���ŷ�ʹ���С���");	                
	        me->set_2("travel.z", z);
	        me->set_2("travel.p", p);
	        me->set_2("travel.money", 0);
	        set_effect(me, EFFECT_TRAVEL, 3);
                return 1;
        }
        else
        {
                write_user(me, ECHO "��������û���κ�Ч����");
                return 0;
        }
}
