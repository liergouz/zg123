
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8607);
        set_picid_2(8607);

        set_level(25);
        set_value(11100);
        set_max_lasting(5599);
        set("cp", 0);
        set("pp", 27);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
