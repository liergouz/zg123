
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// ��������������
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("Ů�����ƹ�");
        set_picid_1(7523);
        set_picid_2(7523);

        set_level(120);
        set_value(57000);
        set_max_lasting(27599);
        set("ap+", 454);
        set("dp+", 40);
        set("hp+", 100);
        set("double", 200);
        set("?%+", 200);
 	set_item_color(3);	//��ɫ
        setup();

        set_weapon_type(STICK);
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
	return "��Ů���Ŀ��ҷ�������������������Ŀ��ƫ�����ˡ�\n�ڹ���Ŀ���ͬʱ��һ������\nʹ������Ŀ������־��";		
}