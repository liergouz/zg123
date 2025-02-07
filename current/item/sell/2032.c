#include <item.h>
#include <ansi.h>
#include <equip.h>

inherit ITEM;
inherit "/inh/item/diamond";

// ��������ʯʶ��
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
int is_diamond_2() { return 1; }

// ��������Ҫȷ������
int confirm_sell_item() { return 1; }

int get_item_color() {return 3 ;}

// ��������ʯʶ��
int get_item_type() { return ITEM_TYPE_DIAMOND_3; }

// ��������ʯ����
string get_diamond_type() { return "forge"; }

// ��ʯ����ı���־
string get_forge_index() {return "3";}

int is_specal_move() {return 1;}

// ���������촦��
void create()
{
        set_name("�߼�����ʯ");
        set_real_name("����ʯ");
        set_picid_1(4273);
        set_picid_2(4273);
        set_unit("��");
        set_value(50);
        set_level(1);
}

string get_desc() 
{
	return "ֻ�ܶ���4�ǻ���ߵ�װ�����ɼ�ǿ��װ�������Լӳɡ�\n����ʧ�ܣ�װ���ỹԭΪδ�����κζ���ʯ��״̬��\nװ�������Ŷ���Ĵ���Խ�ߣ��ɹ��ʻ�Խ�͡�";
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
	if( equip->is_equip())
	{
		i=equip->get_equip_type();
		if ( i!=WEAPON_TYPE&&i!=ARMOR_TYPE&&i!=HEAD_TYPE&&i!=BOOTS_TYPE&&i!=WAIST_TYPE&&i!=NECK_TYPE)
			return 0;
	}
	if (equip->get_real_name()=="����ʯ" )
	{
		if (item->get_forge_index()!=equip->get_forge_index())
			notify( "����ͬ�Ķ���ʯ�޷����кϳɡ�" );
		else
			notify( "�߼�����ʯ����Ҫ���кϳɡ�" );
		return 1;
	}
	forge = equip->get("forge");
	if (forge==0) level = 0;
	else level = strlen(forge);
	if (level<4)
	{
		notify( "�߼�����ʯֻ�ܶ���4�ǻ���ߵ�װ����" );
		return 1;
	}	
	rate = 10000;		
	for (i=4;i<=level;i++)
	{
		rate = rate * 3 / 5; 
	}
	rate /= 100;
	if ( me->get_vip() && !me->get_save_2("vip_package.trial") )
		rate += 5;
	if (rate>100) rate = 100;	
	if (type==1)
	{
		result = sprintf("װ������ʧ�ܺ�ӳɵ��Ǳ����0��\n��ǰװ���Ķ���ɹ���Ϊ"HIR" %d��"NOR"��\n��ȷ��Ҫ����%s��\n"
			ESC "ȷ��\nmix3 0# %x# %x#\n"
			ESC "ȡ��",
			rate, equip->get_name(), getoid(equip), getoid(item) );
		send_user(me, "%c%c%w%s", ':', 3, 0, result);			       			
		return 1;
	}		
	return 1;
}