
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("�������");
        set_picid_1(8712);
        set_picid_2(8712);

        set_level(100);
        set_value(21800);
        set_max_lasting(10899);
        set("dp", 90);
        set("pp", 90);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�������";
}
