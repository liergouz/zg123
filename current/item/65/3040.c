
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("�Ƶ�ñ");
        set_picid_1(6536);
        set_picid_2(6536);

        set_level(40);
        set_value(8500);
        set_max_lasting(7899);
        set("dp", 56);
        set("pp", 22);

        setup();

        set_gender(1);
        set_head_code(43);
}

// ��������ȡ����
string get_desc()
{
        return "�Ƶ�ñ";
}
