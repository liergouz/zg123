
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("�������");
        set_picid_1(8709);
        set_picid_2(8709);

        set_level(20);
        set_value(3400);
        set_max_lasting(6099);
        set("dp", 10);
        set("pp", 10);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�������";
}
