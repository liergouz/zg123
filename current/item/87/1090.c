
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8710);
        set_picid_2(8710);

        set_level(90);
        set_value(20000);
        set_max_lasting(12999);
        set("dp", 90);
        set("pp", 75);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
