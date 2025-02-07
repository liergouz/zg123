#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;

int get_item_value() {return 350 ;}
int get_item_value_2() {return 250 ;}
int get_item_number() {return 10001018 ;}
int get_item_color() {return 1 ;}

// ���������촦��
void create()
{
        set_name( "������" );
        set_picid_1(9120);
        set_picid_2(9120);
	set_value(188);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "ע��������֮�����쵤ҩ����˵���������ߵ���ꡣ\n�����������ɰ�����Ҹ����������ĳͷ���\n��ҿ�ѡ��ԭ�ظ�����ߵ�ǰ�������һ����ת�㸴�����ָ��ʽ��\n�������Ѫ�뷨��ȫ���ָ���";
}

// ������ʹ��Ч��
int revive( object me, int type ) { return __FILE__ ->revive_call(me,this_object(), type); }

// ������ʹ��Ч��(���߸���)
int revive_call( object me,object item, int type)
{
	int z, x, y, p;
        if( me->is_die() )
        {
                set_effect(me, EFFECT_USER_DIE, 0);
                me->set_die(0);
                me->set_hp( me->get_max_hp() );
                me->set_mp( me->get_max_mp() );

                me->set_login_flag(2);    // ��ת����
                set_invisible(me, 1);
                set_effect(me, EFFECT_USER_LOGIN, 2);
                item->add_amount(-1);
        }
        if (type==2)
        {
        	z = get_z(me);
        	p = get_jumpin(z, -1);
        	if( p )
        	{
        		x = p / 1000;  y = p % 1000;
        		me->add_to_scene(z, x, y, 3);
        	}
        }
        return 1;
}
