
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8713);
        set_picid_2(8713);

        set_level(60);
        set_value(12500);
        set_max_lasting(10299);
        set("dp", 60);
        set("pp", 45);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
