
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(8612);
        set_picid_2(8612);

        set_level(20);
        set_value(8000);
        set_max_lasting(4899);
        set("cp", 28);
        set("pp", 26);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
