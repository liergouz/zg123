
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("ɳ������");
        set_picid_1(8707);
        set_picid_2(8707);

        set_level(20);
        set_value(2500);
        set_max_lasting(6699);
        set("dp", 18);
        set("pp", 5);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ɳ������";
}
