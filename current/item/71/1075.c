
#include <equip.h>

inherit WEAPON;

// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("�»�");
        set_picid_1(7808);
        set_picid_2(7808);

        set_level(75);
        set_value(4000);
        set_max_lasting(1099);
        set("ap+", 10);
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
	return "���صİ������ƺ�����ĳЩ����";		
}