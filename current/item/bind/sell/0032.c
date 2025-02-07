#include <item.h>
#include <ansi.h>
#include <equip.h>

inherit ITEM;
inherit "/inh/item/diamond";

int get_item_value() {return 49 ;}
int get_item_value_2() {return 49 ;}
int get_item_number() {return 10001027 ;}

// ��������ʯʶ��
int is_diamond_2() { return 1; }

// ��������Ҫȷ������
int confirm_sell_item() { return 1; }

int get_item_color() {return 1 ;}

// ��������ʯʶ��
int get_item_type() { return ITEM_TYPE_DIAMOND_3; }

// ��������ʯ����
string get_diamond_type() { return "forge"; }

// ��ʯ����ı���־
string get_forge_index() {return "1";}

int is_specal_move() {return 1;}

// ���������촦��
void create()
{
        set_name("��������ʯ");
        set_real_name("����ʯ");
        set_picid_1(4270);
        set_picid_2(4270);
        set_unit("��");
        set_value(50);
        set_level(1);
        // -- ��ԭװ��������Ӱ�����
        set_no_give(1);
        set_no_sell(1);
        //        
}

string get_short(object me)
{
	return "ֻ�ܶ���1�ǻ����µ�װ�����ɼ�ǿ��װ�������ԡ�\n������������ʯ�ɺϳ�һ���м�����ʯ��";
}

// ��������ȡ����
string get_desc()
{
        return "ֻ�ܶ���1�ǻ����µ�װ�����ɼ�ǿ��װ�������ԡ�\n������������ʯ�ɺϳ�һ���м�����ʯ��";
}

string get_name()
{
	object me = this_object();
	if (!clonep(me)) return "��������ʯ";
	if (me->get_level()>1)
		return sprintf("%d����������ʯ", me->get_level());
	else
		return "��������ʯ";
}

int move_item(object me, object item, object equip)
{
	return __FILE__->move_item_callout(me, item, equip, 1 );
}

int move_item2(object me, object item, object equip)
{
	return __FILE__->move_item_callout(me, item, equip, 2 );
}

int move_item_callout(object me, object item, object equip, int type)
{
	string result, forge;
	object item2;
	int i, p, level, rate;	
	if( equip->is_equip()==0 && equip->get_real_name()!="����ʯ" )  return 0;
	if (item->get_level()!=1)
	{
		notify( "���ҹ���ཫ��ʯ�ֽ�Ϊ������ʯ" );
		return 1;
	}
	if( equip->is_equip())
	{
		i=equip->get_equip_type();
		if ( i!=WEAPON_TYPE&&i!=ARMOR_TYPE&&i!=HEAD_TYPE&&i!=BOOTS_TYPE&&i!=WAIST_TYPE&&i!=NECK_TYPE)
			return 0;
	}
	if (equip->get_real_name()=="����ʯ" && item->get_forge_index()!=equip->get_forge_index())
	{
		notify( "����ͬ�Ķ���ʯ�޷����кϳɡ�" );
		return 1;
	}
	forge = equip->get("forge");
	if (forge==0) level = 0;
	else level = strlen(forge);
	if (i>0 && level>1)
	{
		notify( "��������ʯֻ�ܶ�����1�����µ�װ���ϡ�" );
		return 1;
	}
	rate = 100;
	if (type==1)
	{
		if (i==0 )
		{
			result = sprintf("��ȷ��Ҫ��������������ʯ�ϳ�Ϊһ���м�����ʯ��\n"
			        ESC "%c\n" ESC "\nmix2 0# %x# %x#\n"
			        , 1, getoid(item), getoid(equip) );
			send_user(me, "%c%c%s", 0x59, 1, result);
		}
		else
		{
			result = sprintf("װ������ʧ�ܺ�ӳɵ��Ǳ����0��\n��ǰװ���Ķ���ɹ���Ϊ"HIR" %d��"NOR"��\n��ȷ��Ҫ����%s��\n"
				ESC "ȷ��\nmix3 0# %x# %x#\n"
				ESC "ȡ��",
			        rate, equip->get_name(), getoid(equip), getoid(item) );

			send_user(me, "%c%c%w%s", ':', 3, 0, result);
		}		       			
		return 1;
	}		
	return 1;
}