
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8714);
        set_picid_2(8714);

        set_level(100);
        set_value(32500);
        set_max_lasting(7699);
        set("dp", 85);
        set("pp", 100);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
