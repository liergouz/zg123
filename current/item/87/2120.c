
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

        set_level(120);
        set_value(27500);
        set_max_lasting(15699);
        set("dp", 123);
        set("pp", 108);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
