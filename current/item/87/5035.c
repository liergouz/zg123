
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8708);
        set_picid_2(8708);

        set_level(35);
        set_value(9750);
        set_max_lasting(5799);
        set("dp", 22);
        set("pp", 35);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
