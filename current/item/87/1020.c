
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("Ƥ������");
        set_picid_1(8701);
        set_picid_2(8701);

        set_level(20);
        set_value(2500);
        set_max_lasting(6699);
        set("dp", 20);
        set("pp", 5);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "Ƥ������";
}
