
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8714);
        set_picid_2(8714);

        set_level(110);
        set_value(36000);
        set_max_lasting(7999);
        set("dp", 98);
        set("pp", 112);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
