
#include <ansi.h>

inherit ITEM;
inherit USABLE;

// ���������촦��
void create()
{
        set_name( "����" );
        set_picid_1(9534);
        set_picid_2(9534);
        set_unit( "��" );
        set_value(1);

        set_no_drop(1);
        set_no_get(1);
        set_no_give(1);
        set_no_sell(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "��ũ����ֲ�����������"; 
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me, object item )
{
        object npc;
        string id;
        int p, z, x, y;

        if(     stringp( id = me->get_task("plant") ) 
        &&      objectp( npc = find_living(id) ) 
        &&      npc->is_plant() )
        {
                send_user(me, "%c%s", '!', "�����ڸ������������");
                return 0;
        }

        z = get_z(me);  x = get_x(me);  y = get_y(me);

        switch( get_d(me) )
        {
      default : x ++;         break;
       case 2 : x ++;  y --;  break;
       case 3 :        y --;  break;
       case 4 : x --;  y --;  break;
       case 5 : x --;         break;
       case 6 : x --;  y ++;  break;
       case 7 :        y ++;  break;
       case 8 : x ++;  y ++;  break;
        }

        if( !inside_jumpin(z, x, y, 18) )
        {
                send_user(me, "%c%s", '!', "���ý�������ֲ������");
                return 0;
        }

        if( p = get_valid_xy(z, x, y, IS_CHAR_BLOCK) )
        {
                npc = new( "/npc/std/9210" );
                npc->set_name( sprintf( "(%s)", me->get_name() ) );    // ����ũ��

                npc->add_to_scene(z, p / 1000, p % 1000, 3);
                me->set_task("plant", sprintf( "%x#", getoid(npc) ) );

                write_user(me, ECHO "�����������ֲ�����ӡ�" );
        }

        return 1;
}
