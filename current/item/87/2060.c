
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("̤������");
        set_picid_1(8711);
        set_picid_2(8711);

        set_level(60);
        set_value(12500);
        set_max_lasting(10299);
        set("dp", 63);
        set("pp", 48);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "̤������";
}
