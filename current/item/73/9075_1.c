
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
        set_name("Ů���ǵķ�ŭ");
        set_picid_1(7323);
        set_picid_2(7323);

        set_level(120);
        set_value(57000);
        set_max_lasting(27599);
        set("ap+", 380);
        set("cp+", 760);
        set("dp+", 50);
        set("hp+", 100);
        set("double", 200);
        set("?%+", 200);
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
	return "��Ů���ǵķ�ŭ��\n���ӶԻ�����������ɵ��మЧ��\n������Ч�������300��";		
}