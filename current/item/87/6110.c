
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("Ǭ������");
        set_picid_1(8710);
        set_picid_2(8710);

        set_level(110);
        set_value(36000);
        set_max_lasting(7999);
        set("dp", 95);
        set("pp", 110);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "Ǭ������";
}
