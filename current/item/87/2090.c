
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8714);
        set_picid_2(8714);

        set_level(90);
        set_value(20000);
        set_max_lasting(12999);
        set("dp", 93);
        set("pp", 78);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
