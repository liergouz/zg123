
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// ��������������
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_family() { return 9; }

// ���������촦��
void create()
{
        set_name("�񳿱���");
        set_picid_1(6872);
        set_picid_2(6872);

        set_level(75);
        set_value(20000);
        set_max_lasting(14099);
        set("ap+", 190);
        set("cp+", 380);
        set("dp+", 15);
        set("hp+", 50);
        set("double", 100);
        set("?%+", 100);
	set_item_color(3);	//��ɫ
        setup();

        set_weapon_type(SWORD);
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
	return "��̫���񳿵������õķ���������\n���ӷ�������ɵ��˺�Ч��\n������Ч�������50��";		
}