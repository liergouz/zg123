
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("���������");
        set_picid_1(7023);
        set_picid_2(7023);

        set_level(120);
        set_value(57000);
        set_max_lasting(27599);
        set("ap+", 610);
        set("dp+", 40);
        set("pp+", 100);
        set("!%+", 200);
        set("?%+", 200);
 	set_item_color(3);	//��ɫ
        setup();

        set_weapon_type(UNARMED);
}

// ��������ȡ��������
int get_weapon_level() { return 75; }

// ��������ȡ����
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc()
{
        return "��ȭ����װ��";
}

//
string get_tail_desc()
{
	return "�������������������������\n��˭�����ṥ��֮����һ��\n�ļ��ʸ�������һ�����Ļ���";	
}