#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("����Ƥ��");
        set_picid_1(8705);
        set_picid_2(8705);

	set_unit("��");
        set_level(12);
        set_value(1500);
        set_max_lasting(3699);
        set("dp", 13);
	set("!%", 10);
        setup();

}

// ��������ȡ����
string get_desc()
{
        return "����Ƥ��";
}
