
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8708);
        set_picid_2(8708);

        set_level(45);
        set_value(8750);
        set_max_lasting(8899);
        set("dp", 43);
        set("pp", 30);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
