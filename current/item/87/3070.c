
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8710);
        set_picid_2(8710);

        set_level(70);
        set_value(15000);
        set_max_lasting(11199);
        set("dp", 68);
        set("pp", 55);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
