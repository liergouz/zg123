
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("ޭľ����");
        set_picid_1(8712);
        set_picid_2(8712);

        set_level(65);
        set_value(20250);
        set_max_lasting(6699);
        set("dp", 53);
        set("pp", 67);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ޭľ����";
}
