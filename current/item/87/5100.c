
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

        set_level(100);
        set_value(32500);
        set_max_lasting(7699);
        set("dp", 87);
        set("pp", 100);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
