
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8710);
        set_picid_2(8710);

        set_level(90);
        set_value(29000);
        set_max_lasting(7399);
        set("dp", 77);
        set("pp", 90);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
