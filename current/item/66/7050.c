
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("Ծ���ñ");
        set_picid_1(6615);
        set_picid_2(6615);

        set_level(50);
        set_value(18000);
        set_max_lasting(6699);
        set("dp", 37);
        set("pp", 57);

        setup();

        set_gender(2);
        set_head_code(53);
}

// ��������ȡ����
string get_desc()
{
        return "Ծ���ñ";
}
