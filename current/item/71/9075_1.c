
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// ��������������
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("���޵��黨");
        set_picid_1(7123);
        set_picid_2(7123);

        set_level(120);
        set_value(33000);
        set_max_lasting(36099);
        set("ap+", 610);
        set("dp+", 40);
        set("pp+", 100);
        set("!%+", 200);
        set("?%+", 200);
 	set_item_color(3);	//��ɫ
        setup();

        set_weapon_type(THROWING);
}

// ��������ȡ��������
int get_weapon_level() { return 75; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}

//
string get_tail_desc()
{
	return "�����޵��黨����ɱ�������Ρ�\nʹ�����黨�����ܹ��˺��������";	
}