
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8711);
        set_picid_2(8711);

        set_level(30);
        set_value(8000);
        set_max_lasting(5599);
        set("dp", 15);
        set("pp", 30);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
