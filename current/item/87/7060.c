
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8710);
        set_picid_2(8710);

        set_level(60);
        set_value(18500);
        set_max_lasting(6499);
        set("dp", 48);
        set("pp", 62);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
