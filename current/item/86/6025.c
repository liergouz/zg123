
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8607);
        set_picid_2(8607);

        set_level(25);
        set_value(12500);
        set_max_lasting(4899);
        set("cp", 40);
        set("pp", 30);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
