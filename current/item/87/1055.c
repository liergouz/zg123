
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8714);
        set_picid_2(8714);

        set_level(55);
        set_value(11250);
        set_max_lasting(9799);
        set("dp", 55);
        set("pp", 40);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
