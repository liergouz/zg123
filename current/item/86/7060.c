
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("ڤ������");
        set_picid_1(8656);
        set_picid_2(8656);

        set_level(60);
        set_value(44000);
        set_max_lasting(5499);
        set("cp", 110);
        set("pp", 70);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ڤ������";
}
