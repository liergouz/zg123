
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

        set_level(70);
        set_value(22000);
        set_max_lasting(6799);
        set("dp", 57);
        set("pp", 70);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
